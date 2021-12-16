#include <iostream>
#include <time.h>
#include <algorithm>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

const int island_side_a = 10;
const int island_side_b = 10;
int treasure_cell;
bool treasure_is_found = false;
int winner_group_number;

std::vector<std::string> island;
std::vector<int> groups;
std::vector<std::thread> threads;
std::vector<int> exploring_cells;
std::queue<int> free_threads;

std::mutex mutex1;
std::mutex mutex2;
std::mutex mutex3;

std::condition_variable cvtask;
std::condition_variable cvthread;
std::condition_variable cvfound;

void printIsland();
void intro();
void runGroup(int group_number, int group_size);

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "rus");
	intro();
	treasure_cell = std::rand() % 100;

	for (int i = 0; i < std::min((int)groups.size(), 100); i++) {
		std::thread thread(runGroup, i, groups[i]);
		threads.push_back(std::move(thread));
		free_threads.push(i);
		exploring_cells.push_back(-1);
	}

	for (int i = 0; i < 100; i++) {
		{
			std::unique_lock<std::mutex> lock(mutex3);
			cvthread.wait(lock, [] {return !free_threads.empty(); });
		}

		if (treasure_is_found) {
			break;
		}

		{
			std::unique_lock<std::mutex> lock(mutex3);
			exploring_cells[free_threads.front()] = i;
			free_threads.pop();
		}
		cvtask.notify_all();
	}

	{
		std::unique_lock<std::mutex> lock(mutex3);
		cvfound.wait(lock, [] {return treasure_is_found; });
	}

	{
		std::unique_lock<std::mutex> lock(mutex3);
		for (int i = 0; i < exploring_cells.size(); i++) exploring_cells[i] = -2;
	}
	cvtask.notify_all();

	for (std::thread& thread : threads) {
		thread.join();
	}
	std::cout << "Group #" << winner_group_number << " has found a treasure.";
}

void intro() {
	for (int i = 0; i < 100; i++) {
		island.push_back(" ");
	}

	for (int i = 0; i < 5; i++) {
		groups.push_back(2);
	}

	std::cout << "We have 10 pirates who were divided by Silver to 5 groups and 2 pirates in each one and an island of size 10x10.\n"
		"Type out 'start' to explore." << std::endl;
	std::string word;
	while (true) {
		std::cin >> word;
		if (word == "start") {
			break;
		}
	}
}

void printIsland() {
	std::cout << "Island:\n";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << island[i * 10 + j] << " ";
		}
		std::cout << std::endl;
	}
}

void runGroup(int group_number, int size) {
	while (true) {
		{
			std::unique_lock<std::mutex> lock1(mutex1);
			cvtask.wait(lock1, [group_number] { return exploring_cells[group_number] != -1; });
		}

		int cell = exploring_cells[group_number];
		if (cell == -2) {
			return;
		}

		{
			std::unique_lock<std::mutex> lock2(mutex2);
			std::cout << "Group #" << group_number + 1 << " is to explore a cell #" << cell << std::endl;
		}
		std::this_thread::sleep_for(std::chrono::seconds(5 / size));
		std::unique_lock<std::mutex> lock3(mutex3);

		if (cell == treasure_cell) {
			island[cell] = "X";
			{
				std::unique_lock<std::mutex> lock(mutex2);
				std::cout << "Group #" << group_number << " has explored cell #" << cell << std::endl;
				std::cout << "The treasure has just been found!";
				printIsland();
			}
			winner_group_number = group_number;
			treasure_is_found = true;
			free_threads.push(group_number);
			cvthread.notify_one();
			cvfound.notify_one();
			return;
		}
		else {
			island[cell] = "-";
			{
				std::unique_lock<std::mutex> lock(mutex2);
				std::cout << "Group #" << group_number << " has explored cell #" << cell << std::endl;
				printIsland();
			}

			if (exploring_cells[group_number] != -2)
				exploring_cells[group_number] = -1;
			free_threads.push(group_number);
			cvthread.notify_one();
		}
	}
}
