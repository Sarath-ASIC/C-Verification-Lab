// Spec Details
// --------------------------------------------------------------
// constraint length = 3
// Generator polynomial : 
//                       G1 : 111
//                       G2 : 101
// Code Rate : 1/2
// Memory (Container) = 2 bit
// ---------------------------------------------------------------


#include <stdio.h>

int main()
{
    int input[100];
    int n;
    int reg1 = 0, reg2 = 0;
    int i;
    int out1, out2;

    printf("Enter the number of input bits: ");
    scanf("%d", &n);

    printf("Enter the input bits (0 or 1): ");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
    }

    printf("\nEncoded output: ");

    for (i = 0; i < n; i++)
    {
        int current = input[i];

        // Generator G1 = 111
        out1 = current ^ reg1 ^ reg2;

        // Generator G2 = 101
        out2 = current ^ reg2;

        printf("%d%d ", out1, out2);

        // Shift the register
        reg2 = reg1;
        reg1 = current;
    }

    printf("\n");

    return 0;
}

// ------------------END FILE ------------------------------------
