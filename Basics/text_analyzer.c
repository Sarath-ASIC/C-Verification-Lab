#include <stdio.h>
#include <ctype.h>

int main() {
    char text[100];
    int vowels = 0, consonants = 0, digits = 0, spaces = 0;
    int i = 0;

    printf("Enter a sentence: ");
    fgets(text, sizeof(text), stdin);

    while (text[i] != '\0') {
        char ch = tolower((unsigned char)text[i]);

        if (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u') {
            vowels++;
        } else if (isalpha((unsigned char)ch)) {
            consonants++;
        } else if (isdigit((unsigned char)ch)) {
            digits++;
        } else if (ch == ' ') {
            spaces++;
        }

        i++;
    }

    printf("\nVowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);
    printf("Spaces: %d\n", spaces);

    return 0;
}
