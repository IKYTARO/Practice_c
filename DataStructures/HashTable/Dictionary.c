#include <stdio.h>
#include <stdlib.h>

unsigned w = 32;
unsigned M = 10;

unsigned hash_int(unsigned a, unsigned b, unsigned x) {
    return (a*x + b) >> (w - M);
}

unsigned hash_str(char const *str, unsigned size) {
    return 0;
}