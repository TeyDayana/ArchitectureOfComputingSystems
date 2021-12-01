global RECTANGLE
global TRIANGLE
global CIRCLE
%include "macros.mac"

section .data
    error1  db  "Incorrect number of arguments! Must be five with -f <input_file> or -n <number_of_figures> and two files for output.", 10, 0
    error2  db  "Incorrect command line! Must be -f <input_file> or -n <number_of_figures> and two files for output.", 10, 0
    randArg db  "-n", 0
    fileArg db  "-f", 0
    length  dd  0   ; длина контейнера
    RECTANGLE   dd  1
    TRIANGLE    dd  2
    CIRCLE      dd  3
    numOneD     dq  1.0
section .bss
    argc    resd    1
    size    resd    1
    contnr  resb    320000   ; контейнер с фигурами
    perimAv resq    1
    startTime   resq    2
    finishTime  resq    2
    differTime  resq    2
    fileIn      resq    1
    fileOut1    resq    1
    fileOut2    resq    1
section .text
    global main

main:
    ; для корректной работы
    push rbp
    mov rbp, rsp
    mov dword [argc], edi   ; помещение элемента в массив
    mov r12, rdi            ; rdi содержит количество аргументов
    mov r13, rsi            ; rsi содержит адрес массива аргументов
.printArgs:
    inc rbx                             ; увеличение rbx на 1
    cmp rbx, r12                        ; проверка на равенство
    jl  .printArgs                      ; цикл
    cmp r12, 5                          ; проверка на 5 аргументов
    je  .checkArgs
    PrintStrData    error1, [stdout]    ; вывод сообщения об ошибке в терминал
    jmp .exit                           ; переход к маркировке 'exit:'
.checkArgs:
    mov rax, 228
    xor edi, edi
    lea rsi, [startTime]
    syscall
    PrintStrLn  "Start", [stdout]
    ; проверка второго аргумента: -f/n
    mov     rdi, randArg
    mov     rsi, [r13 + 8]
    ; проверка на равенство '-n'
    call    strcmp
    cmp     rax, 0
    je      .gener
    mov     rdi, fileArg
    mov     rsi, [r13 + 8]
    ; проверка на равенство '-f'
    call    strcmp
    cmp     rax, 0
    je      .fromFile
    PrintStrData    error2, [stdout]
    jmp             .exit
.gener:
    ; случайная генерация
    mov     rdi, [r13 + 16]
    call    atoi
    mov     [size], eax
    mov eax, [size] ; указанное количество фигур
    cmp eax, 1      ; проверка на корректность
    jl  .printError3
    cmp eax, 10000  ; проверка на корректность
    jg  .printError3
    ; установка генератора
    xor     rdi, rdi
    xor     rax, rax
    call    time
    mov     rdi, rax
    xor     rax, rax
    call    srand
    ; установка контейнера
    mov     rdi, contnr ; передача контейнера
    mov     rsi, length ; передача длины
    mov     edx, [size] ; передача размера
    call    RandContnr
    jmp     .task1
.fromFile:
    FileOp  [r13+16], "r", fileIn
    mov     rdi, contnr
    mov     rsi, length
    mov     rdx, [fileIn]
    xor     rax, rax
    call    GetContnr
    FileCl  [fileIn]
    jmp     .task1
.task1:
    ; вывод контейнера
    FileOp      [r13+24], "w", fileOut1
    PrintStrLn  "Color codes: 0 - red, 1 - orange, 2 - yellow, 3 - green, 4 - cyan, 5 - blue, 6 - purple", [fileOut1]
    PrintStrLn  "Filled container:", [fileOut1]
    PrintContnr contnr, [length], [fileOut1]
    FileCl      [fileOut1]
.task2:
    FileOp      [r13+32], "w", fileOut2
    PrintStr    "Average perimeter is ", [fileOut2]
    PerimAver   contnr, [length], [perimAv]
    PrintDouble [perimAv], [fileOut2]
    PrintStrLn  "", [fileOut2]
    PrintContnr contnr, [length], [fileOut2]
    FileCl      [fileOut2]
    PrintStrLn  "See results in files", [stdout]
    mov rax, 228   
    xor edi, edi   
    lea rsi, [finishTime]
    syscall
    mov rax, [finishTime]
    sub rax, [startTime]
    mov rbx, [finishTime+8]
    mov rcx, [startTime+8]
    cmp rbx, rcx
    jge .subNanoOnly
    dec rax
    add rbx, 1000000000    
.subNanoOnly:
    sub rbx, [startTime+8]
    mov [differTime], rax
    mov [differTime+8], rbx
    PrintStr    "Calculaton time = ", [stdout]
    PrintLLUns  [differTime+8], [stdout]
    PrintStr    " nsec", [stdout]
    PrintStr    10, [stdout]
    PrintStrLn "Finish", [stdout]
    jmp .exit
.printError3:
    PrintStrLn  "Incorrect number of figures (3rd command argument). Must be from 1 to 10000", [stdout]
.exit:
leave
ret
