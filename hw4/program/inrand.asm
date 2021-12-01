extern  printf
extern  rand
extern  RECTANGLE
extern  TRIANGLE
extern  CIRCLE

global  RandContnr
RandContnr:
section .bss
    .contnrp    resq    1   ; контейнер
    .lengthp    resq    1   ; количество добавленных фигур
    .sizep      resd    1   ; размер контейнера
section .text
    push    rbp
    mov     rbp, rsp
    mov [.contnrp], rdi ; указатель на начало контейнера
    mov [.lengthp], rsi ; указатель на число фигур
    mov [.sizep], edx   ; указатель на размер
    xor ebx, ebx        ; 0 фигур
.addFig:
    cmp ebx, edx
    jge .exit
    ; рабочие регистры
    push    rdi
    push    rbx
    push    rdx
    call    RandShape
    cmp     rax, 0
    jle     .exit
    pop rdx
    pop rbx
    inc rbx
    pop rdi
    add rdi, 32 ; следующая фигура
    jmp .addFig
.exit:
    ; перенос и занесение длины
    mov rax, [.lengthp]
    mov [rax], ebx
leave
ret

; генерация фигуры
global  RandShape
RandShape:
section .data
    .i3     dq      3
section .bss
    .shapep resq    1   ; фигура
section .text
    push    rbp
    mov     rbp, rsp
    mov [.shapep], rdi  ; указатель на фигуру
    ; определение фигуры
    xor     eax, eax
    call    rand        ; вызов генератора
    xor     edx, edx
    idiv    qword[.i3]  ; извлечение числа от 0 до 2
    mov     eax, edx
    inc     eax
    ; запись ключа
    mov rdi, [.shapep]
    mov [rdi], eax
    cmp eax, [RECTANGLE]
    je  .randRect
    cmp eax, [TRIANGLE]
    je  .randTri
    cmp eax, [CIRCLE]
    je  .randCirc
    xor eax, eax
    jmp .exit
.randRect:
    ; прямоугольник
    add     rdi, 4
    call    RandRect
    mov     eax, 1
    jmp     .exit
.randTri:
    ; треугольник
    add     rdi, 4
    call    RandTri
    mov     eax, 1
    jmp     .exit
.randCirc:
    ; круг
    add     rdi, 4
    call    RandCirc
    mov     eax, 1
    jmp     .exit
.exit:
leave
ret

global  RandomCoord
RandomCoord:
section .data
    .i50   dq  50
section .text
    push    rbp
    mov     rbp, rsp
    xor     rax, rax
    call    rand            ; вызов генератора
    xor     rdx, rdx        ; обнуление
    idiv    qword[.i50]    ; число от 0 до 49
    mov     rax, rdx
    inc     rax
leave
ret

global  RandomCol
RandomCol:
section .data
    .i7   dq  7
section .text
    push    rbp
    mov     rbp, rsp
    xor     rax, rax
    call    rand            ; вызов генератора
    xor     rdx, rdx        ; обнуление
    idiv    qword[.i7]      ; число от 0 до 6
    mov     rax, rdx
leave
ret

global  RandRect
RandRect:
section .bss
    .rectp  resq    1   ; прямоугольник
section .text
    push    rbp
    mov     rbp, rsp
    mov     [.rectp], rdi   ; прямоугольник
    ; генерация измерений
    call    RandomCoord
    mov     rbx, [.rectp]
    mov     [rbx], eax
    call    RandomCoord
    mov     rbx, [.rectp]
    mov     [rbx+4], eax
    call    RandomCoord
    mov     rbx, [.rectp]
    mov     [rbx+8], eax   
    call    RandomCoord
    mov     rbx, [.rectp]
    mov     [rbx+12], eax
    ; проверка на корректность
    ;mov ecx, [rbx]      ; x left top
    ;mov ebx, [rbx+8]    ; x right bottom
    ;cmp ecx, ebx
    ;jle .repeat
    ;mov ecx, [rbx+4]      ; y left top
    ;mov ebx, [rbx+12]    ; y right bottom
    ;cmp ecx, ebx
    ;jle .repeat    
    ; определение цвета
    call    RandomCol
    mov     rbx, [.rectp]
    mov     [rbx+16], eax
leave
ret

global  RandTri
RandTri:
section .bss
    .trip   resq    1   ; треугольник
section .text
    push    rbp
    mov     rbp, rsp
    mov     [.trip], rdi   ; треугольник
    ; генерация измерений
    call    RandomCoord
    mov     rbx, [.trip]
    mov     [rbx], eax
    call    RandomCoord
    mov     rbx, [.trip]
    mov     [rbx+4], eax
    call    RandomCoord
    mov     rbx, [.trip]
    mov     [rbx+8], eax   
    call    RandomCoord
    mov     rbx, [.trip]
    mov     [rbx+12], eax   
    call    RandomCoord
    mov     rbx, [.trip]
    mov     [rbx+16], eax   
    call    RandomCoord
    mov     rbx, [.trip]
    mov     [rbx+20], eax
    ; определение цвета
    call    RandomCol
    mov     rbx, [.trip]
    mov     [rbx+24], eax
leave
ret

global  RandCirc
RandCirc:
section .bss
    .circp  resq    1   ; круг
section .text
    push    rbp
    mov     rbp, rsp
    mov     [.circp], rdi   ; круг
    ; генерация измерений
    call    RandomCoord
    mov     rbx, [.circp]
    mov     [rbx], eax
    call    RandomCoord
    mov     rbx, [.circp]
    mov     [rbx+4], eax
    call    RandomCoord
    mov     rbx, [.circp]
    mov     [rbx+8], eax
    ; определение цвета
    call    RandomCol
    mov     rbx, [.circp]
    mov     [rbx+12], eax
leave
ret
