; вычисление периметров
extern  RECTANGLE
extern  TRIANGLE
extern  CIRCLE

global  PerimRect
PerimRect:
section .text
    push    rbp
    mov     rbp, rsp
    mov eax, [rdi]
    sub eax, [rdi + 8]
.abs1:
    neg eax
    js  .abs1
    ;
    mov ebx, [rdi + 4]
    sub ebx, [rdi + 12]
.abs2:
    neg ebx
    js  .abs2
    ;
    add eax,ebx
    shl eax, 1
    cvtsi2sd    xmm0, eax
    movsd       [rdi + 20], xmm0
leave
ret

global  PerimTri
PerimTri:
section .data
    sideA   dq  0
    sideB   dq  0
    sideC   dq  0
section .text
    push    rbp
    mov     rbp, rsp
    mov         eax, [rdi]
    sub         eax, [rdi + 8]
    imul        eax, eax
    mov         ebx, [rdi + 4]
    sub         ebx, [rdi + 12]
    imul        ebx, ebx
    add         eax, ebx
    cvtsi2sd    xmm0, eax
    movsd       xmm1, xmm0
    sqrtsd      xmm0, xmm1
    movsd       [sideA], xmm0
    ;
    mov         eax, [rdi + 8]
    sub         eax, [rdi + 16]
    imul        eax, eax
    mov         ebx, [rdi + 12]
    sub         ebx, [rdi + 20]
    imul        ebx, ebx
    add         eax, ebx
    cvtsi2sd    xmm0, eax
    movsd       xmm1, xmm0
    sqrtsd      xmm0, xmm1
    movsd       [sideB], xmm0
    ;
    mov         eax, [rdi + 16]
    sub         eax, [rdi]
    imul        eax, eax
    mov         ebx, [rdi + 20]
    sub         ebx, [rdi + 4]
    imul        ebx, ebx
    add         eax, ebx
    cvtsi2sd    xmm0, eax
    movsd       xmm1, xmm0
    sqrtsd      xmm0, xmm1
    movsd       [sideC], xmm0
    ;
    movsd   xmm0, [sideA]
    addsd   xmm0, [sideB]
    addsd   xmm0, [sideC]
    movsd   [rdi + 28], xmm0
leave
ret

global  PerimCirc
PerimCirc:
section .data
    pi  dq  3.14
section .text
    push    rbp
    mov     rbp, rsp
    mov         eax, [rdi + 8]
    add         eax, eax
    cvtsi2sd    xmm0, eax
    mulsd       xmm0, [pi]
    movsd       [rdi + 16], xmm0
leave
ret

global  PerimAv
PerimAv:
section .data
    .sum    dq  0.0   
section .text
    push    rbp
    mov     rbp, rsp
    mov     ebx, esi        
    xor     ecx, ecx        
    movsd   xmm2, [.sum]    
.addPerim:
    cmp     ecx, ebx        
    jge     .finish
    push    rbx
    push    rcx
    mov     r10, rdi        
    call    Perim  
    addsd   xmm2, xmm0
    pop rcx
    pop rbx
    inc ecx
    add r10, 32         
    mov rdi, r10        
    jmp .addPerim
.finish:
    cvtsi2sd    xmm1, ebx
    divsd       xmm2, xmm1
    movsd       xmm0, xmm2
leave
ret

global Perim
Perim:
section .text
    push    rbp
    mov     rbp, rsp
    mov         eax, [rdi]
    cmp         eax, [RECTANGLE]
    je          .perimRect
    cmp         eax, [TRIANGLE]
    je          .perimTri
    cmp         eax, [CIRCLE]
    je          .perimCirc
    xor         eax, eax
    cvtsi2sd    xmm0, eax
    jmp         .exit
.perimRect:
    add     rdi, 4
    call    PerimRect
    jmp     .exit
.perimTri:
    add     rdi, 4
    call    PerimTri
    jmp     .exit
.perimCirc:
    add     rdi, 4
    call    PerimCirc
    jmp     .exit
.exit:
leave
ret
