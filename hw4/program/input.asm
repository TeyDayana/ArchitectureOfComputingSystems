extern  printf
extern  fscanf
extern  fprintf

extern  RECTANGLE
extern  TRIANGLE
extern  CIRCLE

global  GetContnr
GetContnr:
section .bss
    .contnrp    resq    1
    .lengthp    resq    1
    .file       resq    1
section .text
    push    rbp
    mov     rbp, rsp
    mov [.contnrp], rdi
    mov [.lengthp], rsi
    mov [.file], rdx
    xor rbx, rbx
    mov rsi, rdx
.getFig:
    push    rdi
    push    rbx
    mov     rsi, [.file]
    mov     rax, 0
    call    GetShape
    cmp     eax, 0
    jle     .exit
    pop rbx
    pop rdi
    inc rbx
    add rdi, 32
    jmp .getFig
    jmp .exit
.exit:
    mov rax, [.lengthp]
    mov [rax], ebx
leave
ret

global  GetShape
GetShape:
section .data
    .fmtIn  db  "%d", 0
section .bss
    .file   resq    1
    .shapep resq    1
section .text
    push    rbp
    mov     rbp, rsp
    mov [.shapep], rdi
    mov [.file], rsi
    mov     rdi, [.file]
    mov     rsi, .fmtIn
    mov     rdx, [.shapep]
    xor     rax, rax
    call    fscanf
    mov rcx, [.shapep]
    mov eax, [rcx]
    cmp eax, [CIRCLE]
    je  .getCirc
    cmp eax, [RECTANGLE]
    je  .getRect
    cmp eax, [TRIANGLE]
    je  .getTri
    xor eax, eax
    jmp .exit
.getRect:
    mov     rdi, [.shapep]
    add     rdi, 4
    mov     rsi, [.file]
    call    GetRect
    mov     rax, 1
    jmp     .exit
.getTri:
    mov     rdi, [.shapep]
    add     rdi, 4
    mov     rsi, [.file]
    call    GetTri
    mov     rax, 1
    jmp     .exit
.getCirc:
    mov     rdi, [.shapep]
    add     rdi, 4
    mov     rsi, [.file]
    call    GetCirc
    mov     rax, 1
    jmp     .exit
.exit:
leave
ret

global  GetRect
GetRect:
section .data
    .fmtCol     db  "%d", 0
    .fmtData    db  "%d%d%d%d",0
section .bss
    .file   resq    1
    .rectp  resq    1
section .text
    push    rbp
    mov     rbp, rsp
    mov [.rectp], rdi
    mov [.file], rsi
    mov     rdi, [.file]
    mov     rsi, .fmtData
    mov     rdx, [.rectp]
    mov     rcx, [.rectp]
    add     rcx, 4
    mov     r8, [.rectp]
    add     r8, 8
    mov     r9, [.rectp]
    add     r9, 12
    mov     rax, 0
    call    fscanf
    mov     rdi, [.file]
    mov     rsi, .fmtCol
    mov     rdx, [.rectp]
    add     rdx, 16
    mov     rax, 0
    call    fscanf
leave
ret

global  GetTri
GetTri:
section .data
    .fmtData    db  "%d%d%d%d",0
    .fmtDataCol db  "%d%d%d", 0
section .bss
    .file   resq    1
    .trip   resq    1
section .text
    push    rbp
    mov     rbp, rsp
    mov [.trip], rdi
    mov [.file], rsi
    mov     rdi, [.file]
    mov     rsi, .fmtData
    mov     rdx, [.trip]
    mov     rcx, [.trip]
    add     rcx, 4
    mov     r8, [.trip]
    add     r8, 8
    mov     r9, [.trip]
    add     r9, 12
    mov     rax, 0
    call    fscanf
    mov     rdi, [.file]
    mov     rsi, .fmtDataCol
    mov     rdx, [.trip]
    add     rdx, 16
    mov     rcx, [.trip]
    add     rcx, 20
    mov     r8, [.trip]
    add     r8, 24
    mov     rax, 0
    call    fscanf
leave
ret

global  GetCirc
GetCirc:
section .data
    .fmtData    db  "%d%d%d%d",0
section .bss
    .file   resq    1
    .circp  resq    1
section .text
    push    rbp
    mov     rbp, rsp
    mov [.circp], rdi
    mov [.file], rsi
    mov     rdi, [.file]
    mov     rsi, .fmtData
    mov     rdx, [.circp]
    mov     rcx, [.circp]
    add     rcx, 4
    mov     r8, [.circp]
    add     r8, 8
    mov     r9, [.circp]
    add     r9, 12
    mov     rax, 0
    call    fscanf
leave
ret
