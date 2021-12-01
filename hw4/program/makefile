# makefile for task.asm
task: main.o inrand.o output.o perim.o input.o
	gcc -g -o task main.o inrand.o output.o perim.o input.o -no-pie
main.o: main.asm macros.mac
	nasm -f elf64 -g -F dwarf main.asm -l main.lst
inrand.o: inrand.asm
	nasm -f elf64 -g -F dwarf inrand.asm -l inrand.lst
output.o: output.asm
	nasm -f elf64 -g -F dwarf output.asm -l output.lst
perim.o: perim.asm
	nasm -f elf64 -g -F dwarf perim.asm -l perim.lst
input.o: input.asm
	nasm -f elf64 -g -F dwarf input.asm -l input.lst
