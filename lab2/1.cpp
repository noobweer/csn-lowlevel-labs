#include <iostream>

int main() {
    int a, x, y;

    std::cin >> a >> x;

    _asm {
        mov eax,a
        mov ebx,x

        cmp ebx,eax
        jg  X_Greater_A

        mov ecx,eax
        jmp Y1_Done

    X_Greater_A:
        mov eax,ebx
        cdq
        mov esi,4
        idiv esi
        mov ecx,edx

    Y1_Done:
        mov eax,ebx
        cdq
        idiv a

        mov ebx,3
        cmp eax,ebx
        jg  A_Mul_X

        mov eax,x
        jmp Y2_Done

    A_Mul_X:
        mov eax,a
        imul eax,x

    Y2_Done:
        add eax,ecx
        mov y,eax
    }

    std::cout << y << '\n';

    return 0;
}
