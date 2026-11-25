#include <iostream>
#include <cstring>

int main() {
    char source[256] = "cat dog apple by zebra";
    char dest[256] = "";
    char* starts[64];
    int lens[64];
    int len = strlen(source);
    int word_count = 0;

    __asm {
        cld
        lea edi, source
        mov ecx, len
        xor esi, esi
        mov al, ' '

    parse_loop:
        repe scasb
        je done_parse

        dec edi
        inc ecx
        mov ebx, edi

        repne scasb
        jne last_word

        dec edi
        inc ecx
    last_word:
        mov edx, edi
        sub edx, ebx

        mov starts[esi * 4], ebx
        mov lens[esi * 4], edx
        inc esi

        cmp ecx, 0
        jg parse_loop
    done_parse:
        mov word_count, esi

        cmp word_count, 1
        jle start_build

        mov ecx, word_count
        dec ecx

    outer_loop:
        xor edi, edi
        mov ebx, ecx

    inner_loop:
        mov esi, starts[edi * 4]
        mov eax, lens[edi * 4]
        cmp eax, 3
        jl short_1
        mov al, [esi + 2]
        jmp get_second
    short_1:
        mov al, 0

    get_second:
        mov esi, starts[edi * 4 + 4]
        mov edx, lens[edi * 4 + 4]
        cmp edx, 3
        jl short_2
        mov ah, [esi + 2]
        jmp compare_chars
    short_2:
        mov ah, 0

    compare_chars:
        cmp al, ah
        jbe no_swap

        mov eax, starts[edi * 4]
        mov edx, starts[edi * 4 + 4]
        mov starts[edi * 4], edx
        mov starts[edi * 4 + 4], eax

        mov eax, lens[edi * 4]
        mov edx, lens[edi * 4 + 4]
        mov lens[edi * 4], edx
        mov lens[edi * 4 + 4], eax

    no_swap:
        inc edi
        dec ebx
        jnz inner_loop

        loop outer_loop

    start_build:
        cmp word_count, 0
        je empty_end

        lea edi, dest
        xor ebx, ebx

    build_loop:
        mov esi, starts[ebx * 4]
        mov ecx, lens[ebx * 4]
        rep movsb

        inc ebx
        cmp ebx, word_count
        je finish_build

        mov al, ' '
        stosb
        jmp build_loop

    finish_build:
        mov byte ptr [edi], 0
        jmp all_done

    empty_end:
        mov byte ptr [dest], 0
    all_done:
    }

    std::cout << dest << '\n';
    return 0;
}
