#include <stdio.h>

int main()
{
    /* Hardware register fields */
    int enable = 1;
    int reset = 0;
    int mode = 5;
    int device_id = 0xA5;

    /* Transaction statistics */
    int total_transactions = 1000;
    int failed_transactions = 37;
    int successful_transactions;

    /* Calculate successful transactions */
    successful_transactions = total_transactions - failed_transactions;

    /* Print register information */
    printf("=== Hardware Register ===\n");
    printf("ENABLE    : %d\n", enable);
    printf("RESET     : %d\n", reset);
    printf("MODE      : %d\n", mode);
    printf("DEVICE_ID : 0x%X\n", device_id);

    /* Print transaction statistics */
    printf("\n=== Transaction Statistics ===\n");
    printf("Total      : %d\n", total_transactions);
    printf("Failed     : %d\n", failed_transactions);
    printf("Successful : %d\n", successful_transactions);

    return 0;
}
