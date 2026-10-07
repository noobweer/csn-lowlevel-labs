#include <iostream>
#include <bitset>

int multiply9(int num) {
    __asm {
        mov eax,num
        mov ebx,eax

        shl eax,3
        add eax,ebx

        mov num,eax
    }
    return num;
}

int divide4(int num) {
    __asm {
        mov eax,num
        shr eax,2
        mov num,eax
    }
    return num;
}

int main() {
    int frstNum, scndNum, res;
    std::cin >> frstNum >> scndNum;

    frstNum = multiply9(frstNum);
    scndNum = divide4(scndNum);

    std::cout << "frst mul9: " << frstNum << "  " << std::bitset<32>(frstNum) << "\n";
    std::cout << "scnd div4: " << scndNum << "  " << std::bitset<32>(scndNum) << "\n";

    __asm {
        mov eax,frstNum
        and eax,scndNum
        mov res,eax
    }

    std::cout << "after AND: " << res << "  " << std::bitset<32>(res) << "\n";

    __asm {
        mov eax,res
        rol eax, 16
        mov res,eax
    }

    std::cout << "res: " << res << "  " << std::bitset<32>(res) << "\n";
    return 0;
}
