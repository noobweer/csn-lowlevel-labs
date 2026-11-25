#include <iostream>

int main() {
    float a, x, y;
    std::cin >> a >> x;

    float p1[] = { 14.0, 4.0, 2.0 };
    float p2[] = { 5.0, 16.0, 4.0 };
    float p3[] = { 17.0, 8.0, 3.0, 4.0, 2.0, 5.0};

    __asm {
        jmp Part1

        Part1:
            fld p1
            fsub p1 + 4
            fdiv p1 + 8
            jmp Part2

        Part2:
            fld p2 + 4
            fdiv p2 + 8

            fld x
            fsub a
            fsin

            fmul p2
            fadd
            jmp Part3

        Part3:
            fld p3 + 4
            fdiv p3 + 8
            fadd p3

            fld p3 + 16
            fldl2e
            fmul
            fld st(0)
            frndint
            fsub st(1), st(0)
            fxch
            f2xm1
            fld1
            fadd
            fscale
            fstp st(1)

            fld1
            fadd

            fld p3 + 4
            fdiv p3 + 12

            fmul

            fld p3 + 16
            fmul p3 + 20

            fadd

            fdiv
            jmp Result

        Result:
            fmul
            fmul
            fstp y
    }

    std::cout << y;
    return 0;
}
