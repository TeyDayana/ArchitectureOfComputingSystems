extern  printf
extern  fprintf

extern  RECTANGLE
extern  TRIANGLE
extern  CIRCLE
extern  PerimRect
extern  PerimTri
extern  PerimCirc

global  PrintCont
PrintCont:
section .bss
    .contnrp    resq    1   ; контейнер
    .length     resd    1   ; количество выведенных фигур
    .file       resq    1   ; файл
section .text
    push    rbp
    mov     rbp, rsp
    mov [.contnrp], rdi ; указатель на начало контейнера
    mov [.length], esi  ; указатель на число фигур
    mov [.file], rdx    ; указатель на файл
    mov rbx, rsi        ; число фигур
    xor ecx, ecx
    xor edx, edx
    mov rsi, rdx
.printFig:
    cmp     ecx, ebx    ; проверка на окончание
    jge     .exit
    push    rbx
    push    rcx
    ; вывод фигуры
    mov edx, ecx
    mov     rdi, [.contnrp]    ; указатель на файл
    mov     rsi, [.file]
    call    PrintShape
    pop rcx
    pop rbx
    cmp edx, -1
    je .contin
    inc ecx
    jmp .contin
.contin:
    mov rax, [.contnrp]
    add rax, 32
    mov [.contnrp], rax
    jmp .printFig
.exit:
leave
ret

; вывод фигуры
global  PrintShape
PrintShape:
section .data
    .error  db  "Incorrect figure", 10, 0
section .text
    push    rbp
    mov     rbp, rsp
    mov eax, [rdi]  ; указатель на фигуру
    cmp eax, [RECTANGLE]
    je  .printRect
    cmp eax, [TRIANGLE]
    je  .printTri
    cmp eax, [CIRCLE]
    je  .printCirc
    mov     rdi, .error
    mov     rax, 0
    call    fprintf
    jmp     .exit
.printRect:
    ; прямоугольник
    add     rdi, 4
    call    PrintRect
    jmp     .exit
.printTri:
    ; треугольник
    add     rdi, 4
    call    PrintTri
    jmp     .exit
.printCirc:
    ; круг
    add     rdi, 4
    call    PrintCirc
    jmp     .exit
.exit:
leave
ret

global  PrintRect
PrintRect:
section .data
    .output1 db  "Rectangle: (%d, %d) - top left, (%d, %d) - bottom right. ", 0
    .output2 db  "Perimeter is %g. Color code: %d", 10, 0
section .bss
    .rectp  resq    1   ; прямоугольник
    .file   resq    1   ; указатель на файл
    .perim  resq    1   ; посчитанный периметр
section .text
    push    rbp
    mov     rbp, rsp
    ; запись аргументов
    mov     [.rectp], rdi
    mov     [.file], rsi
    call    PerimRect
    movsd   [.perim], xmm0
    ; вывод в файл
    mov rdi, [.file]
    mov rsi, .output1        ; формат
    mov rax, [.rectp]
    mov     edx, [rax]      ; x top left
    mov     ecx, [rax + 4]  ; y top left
    mov     r8, [rax + 8]   ; x bottom right
    mov     r9, [rax + 12]  ; y bottom right
    call    fprintf
    mov rdi, [.file]
    mov rsi, .output2        ; формат
    mov rax, [.rectp]
    movsd   xmm0, [.perim]
    mov     edx, [rax + 16]
    mov     rax, 1          ; для вещественного числа
    call    fprintf
leave
ret

global  PrintTri
PrintTri:
section .data
    .output1 db  "Triangle: (%d, %d) - A, (%d, %d) - B, ", 0
    .output2 db  "(%d, %d) - C. Perimeter is %g. Color code: %d", 10, 0
section .bss
    .trip   resq    1   ; треугольник
    .file   resq    1   ; указатель на файл
    .perim  resq    1   ; посчитанный периметр
section .text
    push    rbp
    mov     rbp, rsp
    ; запись аргументов
    mov     [.trip], rdi
    mov     [.file], rsi
    call    PerimTri
    movsd   [.perim], xmm0
    ; вывод в файл
    mov rdi, [.file]
    mov rsi, .output1        ; формат
    mov rax, [.trip]
    mov     edx, [rax]      ; x1
    mov     ecx, [rax + 4]  ; y1
    mov     r8, [rax + 8]   ; x2
    mov     r9, [rax + 12]  ; y2
    call    fprintf
    mov rdi, [.file]
    mov rsi, .output2        ; формат
    mov rax, [.trip]
    mov     edx, [rax + 16] ; x3
    mov     ecx, [rax + 20] ; y3
    movsd   xmm0, [.perim]
    mov     r8, [rax + 24]
    mov     rax, 1          ; для вещественного числа
    call    fprintf
leave
ret

global  PrintCirc
PrintCirc:
section .data
    .output1 db  "Circle: (%d, %d) - O, r = %d. Perimeter is %g. ", 0
    .output2 db  "Color code: %d", 10, 0
section .bss
    .circp  resq    1   ; круг
    .file   resq    1   ; указатель на файл
    .perim  resq    1   ; посчитанный периметр
section .text
    push    rbp
    mov     rbp, rsp
    ; запись аргументов
    mov     [.circp], rdi
    mov     [.file], rsi
    call    PerimCirc
    movsd   [.perim], xmm0
    ; вывод в файл
    mov rdi, [.file]
    mov rsi, .output1        ; формат
    mov rax, [.circp]
    mov     edx, [rax]      ; Ox
    mov     ecx, [rax + 4]  ; Oy
    mov     r8, [rax + 8]  ; r
    movsd   xmm0, [.perim]
    call    fprintf
    mov rdi, [.file]
    mov rsi, .output2        ; формат
    mov rax, [.circp]
    mov     edx, [rax + 12]
    mov     rax, 1          ; для вещественного числа
    call    fprintf
leave
ret
