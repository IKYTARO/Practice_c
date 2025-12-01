#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*
    Вам предлагается инвертировать N-й по счёту бит в массиве.
    На вход приходит количество чисел, каждое не больше одного байта, 
        далее все эти числа и дальше номер бита.
    Номер бита отсчитывается от нулевого бита нулевой ячейки массива. 
        Нулевой бит первой ячейки будет иметь номер 8 и т.д.
    Посылка должна состоять из программы, считывающей со стандартного ввода массив и 
        число N и выводящей на стандартный вывод массив в котором N-й бит инвертирован.
    В случае если номер запрашиваемого бита больше максимального номера в массиве, 
        массив выводится без изменений.  
 */

/******************************************************************************
 * ЗАДАЧА: Problem BP -- старший и младший бит
 * 
 * ОПИСАНИЕ:
 *   Вам предлагается найти позицию старшего и младшего установленных битов в числе N.
 * 
 * ВХОДНЫЕ ДАННЫЕ:
 *   - input: int число N
 * 
 * ВЫХОДНЫЕ ДАННЫЕ:
 *   - minor_bit: младший бит числа
 *   - major_bit: старший бит числа
 * 
 * ПРИМЕРЫ:
 *   Вход: 2
 *   Выход: 1 1
 * 
 *   Вход: 269971274
 *   Выход: 28 1
 ******************************************************************************/


void check_input_res(int res) {
    if (res == -1) {
        printf("Wrong input!\n");
        abort();
    }
}

void inverse(int* array, unsigned pos) {
    assert(pos >= 0);
    unsigned slot = pos / __CHAR_BIT__;
    unsigned cell = pos % __CHAR_BIT__;
    array[slot] = array[slot] ^ (1u << cell);
}

int main() {
    unsigned size, pos;
    int res = scanf("%u", &size);
    check_input_res(res);

    int* array = calloc(size, sizeof(int));
    int value = 0;
    for (int i = 0; i < size; i++) {
        res = scanf("%i", &value);
        check_input_res(res);
        array[i] = value;
    }

    res = scanf("%u", &pos);
    check_input_res(res);

    if (pos < size * __CHAR_BIT__) 
        inverse(array, pos);
    for (int i = 0; i < size; i++) {
        printf("%i ", array[i]);
    }
    free(array);

    return 0;
}
