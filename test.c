#include <stdio.h>

int main() {
    const int n = 10;
    int result = 1;
    for (int i = 2; i < n; i++) {
        result *= i;
    }
    printf("%d! = %d\n", n, result);
}
