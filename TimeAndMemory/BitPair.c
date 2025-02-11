#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/*
    Вам предлагается найти позицию старшего и младшего установленных битов в числе.
    Посылка должна состоять из программы, считывающей со стандартного ввода число N 
    и выводящей на стандартный вывод номер его старшего и младшего бита.
    В случае если установленных битов в числе нет, вы должны выдать строчку "NO".
 */


struct pair_bit {
    int minor_bit;
    int major_bit;
};

struct pair_bit get_bit2(unsigned x) {
    struct pair_bit answer;
    answer.minor_bit = -1;
    answer.major_bit = 0;
    unsigned curr_val = 0;
    for (int i = 0; i < sizeof(unsigned) * CHAR_BIT; i++) {
        curr_val = (x >> i) & 1u;
        if (curr_val == 1) {
            answer.major_bit = i;
            if (answer.minor_bit == -1) 
                answer.minor_bit = i;
        }
    }

    return answer;
}

int main() {
    unsigned num;
    int res = scanf("%u", &num);
    if (res == -1) {
        printf("Wrong input!\n");
        abort();
    }

    if (num == 0) {
        printf("NO");
    } 
    else {
        struct pair_bit result = get_bit2(num);
        printf("%i %i", result.major_bit, result.minor_bit);
    }

    return 0;
}
