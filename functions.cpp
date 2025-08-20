
#include "functions.h"

int Factorial(int n) {
    int result = 1;
    if (n == 0)
        result = 1;
    else {
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
    }
    return result;
}
