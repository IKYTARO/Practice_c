#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************************************************************************
 * ЗАДАЧА: Problem RXA — реализация автомата
 *
 * ОПИСАНИЕ:
 *   Ваша задача написать программу, обрабатывающую строки как конечный автомат
 *   (рисунок задан в контесте).
 *
 *   char *strcat_r(char *dest, const char *src, int *bufsz);
 *
 *   Программа начинает работу в состоянии 1 и далее получая со stdout символы
 *   делает переходы между состояниями. Любой символ кроме a, b, c так же как и
 *   завершение stdout это конец работы. Если в конце работы вы в одном из
 *   принимающих состояний, верните 1 иначе 0.
 *
 * ПРИМЕРЫ:
 *   Вход: aaababbbcbcbc
 *   Выход: 1
 *
 *   Вход: aaababbbcbabc
 *   Выход: 0
 ******************************************************************************/

int is_step(char c) { return (c == 'a' || c == 'b' || c == 'c'); }

int process_symbol(char c, int state) {
    switch (state) {
        case 1: {
            switch (c) {
                case 'a':
                    return 1;
                case 'b':
                    return 2;
                case 'c':
                    return 5;
            }
        }
        case 2: {
            switch (c) {
                case 'a':
                    return 1;
                case 'b':
                    return 2;
                case 'c':
                    return 3;
            }
        }
        case 3: {
            switch (c) {
                case 'a':
                    return 5;
                case 'b':
                    return 4;
                case 'c':
                    return 3;
            }
        }
        case 4: {
            switch (c) {
                case 'a':
                    return 5;
                case 'b':
                    return 4;
                case 'c':
                    return 3;
            }
        }
        case 5:
            return 5;
    }
}

int main() {
    int state = 1;

    char c;
    while ((c = getchar()) != EOF) {
        if (!is_step(c)) {
            break;
        }

        state = process_symbol(c, state);
    }

    if (state == 1 || state == 5) {
        printf("0\n");
    } else {
        printf("1\n");
    }

    return EXIT_SUCCESS;
}