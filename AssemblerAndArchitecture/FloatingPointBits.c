#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned float_to_uint(float value);
float uint_to_float(unsigned value);
void reverse_bits(unsigned *value);

int main() {
    float input;
    int input_res = scanf("%f", &input);

    if (input_res != 1) {
        abort();
    }

    unsigned uinput = float_to_uint(input);
    reverse_bits(&uinput);
    float output = uint_to_float(uinput);
    printf("%.5f", output);

    return EXIT_SUCCESS;
}

unsigned float_to_uint(float value) {
    unsigned result;
    memcpy(&result, &value, sizeof(unsigned));
    return result;
}

float uint_to_float(unsigned value) {
    float result;
    memcpy(&result, &value, sizeof(float));
    return result;
}

void reverse_bits(unsigned *value) {
    for (int i = 1; i < 23; i += 2) {
        (*value) = (*value) ^ (1u << i);
    }
}