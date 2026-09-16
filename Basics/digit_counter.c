#include <stdio.h>

int main() {
    int number, copy, digits = 0;

    printf("Enter a whole number: ");
    scanf("%d", &number);

    copy = number;

    if (copy == 0) {
        digits = 1;
    } else {
        if (copy < 0) {
            copy = -copy;
        }

        while (copy > 0) {
            copy = copy / 10;
            digits++;
        }
    }

    printf("%d has %d digit(s).\n", number, digits);

    return 0;
}
