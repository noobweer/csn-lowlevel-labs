#include <cstdio>

int leftPartSolve() {
    int leftPart;

    __asm {
        mov eax,11
        imul eax,2

        mov ebx,6
        imul ebx,4

        sub eax,ebx

        mov ebx,15
        sub ebx,7

        cdq
        idiv ebx

        mov leftPart,eax
    }
    return leftPart;
}

int rightPartSolve() {
    int rightPart;

    __asm {
        mov eax,29
        mov ebx,4
        cdq
        idiv ebx
        mov ecx,eax

        mov eax,7
        cdq
        idiv ebx

        add eax,ecx

        mov ebx,2
        add ebx,3
        cdq
        idiv ebx

        mov rightPart,eax
    }
    return rightPart;
}

int main() {
    int leftPart, rightPart;

    leftPart = leftPartSolve();
    std::printf("%d\n", leftPart);

    rightPart = rightPartSolve();
    std::printf("%d\n", rightPart);

    std::printf("%d\n", leftPart-rightPart);

    return 0;
}
