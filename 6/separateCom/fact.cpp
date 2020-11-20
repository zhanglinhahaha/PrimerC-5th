#include "chapter6.h"

int fact(int val) {
    int sum = 1;
    while(val > 1) sum *= val--;
    return sum;
}
