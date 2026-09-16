#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[50];
    int age;

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    printf("Enter your age: ");
    scanf("%d", &age);

    name[strcspn(name, "\n")] = '\0';  // Remove Enter/newline
    name[0] = toupper((unsigned char)name[0]);

    printf("Name length: %zu\n", strlen(name));
    printf("My age is: %d\n", age);

    return 0;
}
