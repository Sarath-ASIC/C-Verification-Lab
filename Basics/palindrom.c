#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char word[50];
    int left, right;
    int isPalindrome = 1;

    printf("Enter one word: ");
    scanf("%49s", word);

    left = 0;
    right = strlen(word) - 1;

    while (left < right) {
        if (tolower((unsigned char)word[left]) !=
            tolower((unsigned char)word[right])) {
            isPalindrome = 0;
            break;
        }

        left++;
        right--;
    }

    if (isPalindrome) {
        printf("%s is a palindrome.\n", word);
    } else {
        printf("%s is not a palindrome.\n", word);
    }

    return 0;
}
