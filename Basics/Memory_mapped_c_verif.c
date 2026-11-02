
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// Register address definitions
#define CTRL_ADDR    0x00
#define STATUS_ADDR  0x04
#define DATA_ADDR    0x08
#define CONFIG_ADDR  0x0C

#define NUM_REGS 4

// Transaction types
typedef enum
{
    WRITE,
    READ
} operation_t;

// Transaction structure
typedef struct
{
    operation_t operation;
    uint32_t address;
    uint32_t data;
} transaction_t;

// DUT register model
uint32_t dut_regs[NUM_REGS] = {0};

// Reference register model
uint32_t ref_regs[NUM_REGS] = {0};

// Convert address into array index
int get_reg_index(uint32_t address)
{
    switch(address)
    {
        case CTRL_ADDR:   return 0;
        case STATUS_ADDR: return 1;
        case DATA_ADDR:   return 2;
        case CONFIG_ADDR: return 3;

        default: return -1;
    }
}

// DUT write operation
void dut_write(uint32_t address, uint32_t data)
{
    int index = get_reg_index(address);

    if(index < 0)
    {
        printf("DUT ERROR: Invalid address\n");
        return;
    }

    dut_regs[index] = data;
}

// Reference model write operation
void reference_write(uint32_t address, uint32_t data)
{
    int index = get_reg_index(address);

    if(index < 0)
        return;

    ref_regs[index] = data;
}

// DUT read operation
uint32_t dut_read(uint32_t address)
{
    int index = get_reg_index(address);

    if(index < 0)
        return 0;

    return dut_regs[index];
}

// Scoreboard checker
void scoreboard_check(uint32_t address)
{
    uint32_t expected;
    uint32_t actual;

    int index = get_reg_index(address);

    if(index < 0)
    {
        printf("CHECKER ERROR: Invalid address\n");
        return;
    }

    expected = ref_regs[index];
    actual = dut_read(address);

    printf("\nAddress  : 0x%02X\n", address);
    printf("Expected : 0x%08X\n", expected);
    printf("Actual   : 0x%08X\n", actual);

    if(expected == actual)
    {
        printf("RESULT   : PASS\n");
    }
    else
    {
        printf("RESULT   : FAIL\n");
    }
}

// Transaction execution
void execute_transaction(transaction_t trans)
{
    if(trans.operation == WRITE)
    {
        printf("\n--- WRITE TRANSACTION ---\n");

        printf("Address : 0x%02X\n", trans.address);
        printf("Data    : 0x%08X\n", trans.data);

        dut_write(trans.address, trans.data);
        reference_write(trans.address, trans.data);
    }

    else if(trans.operation == READ)
    {
        printf("\n--- READ TRANSACTION ---\n");

        scoreboard_check(trans.address);
    }
}

// Main test
int main()
{
    transaction_t test_sequence[] =
    {
        {WRITE, CTRL_ADDR,   0x00000001},
        {READ,  CTRL_ADDR,   0},

        {WRITE, DATA_ADDR,   0x12345678},
        {READ,  DATA_ADDR,   0},

        {WRITE, CONFIG_ADDR, 0x000000A5},
        {READ,  CONFIG_ADDR, 0}
    };

    int total = sizeof(test_sequence) /
                sizeof(test_sequence[0]);

    printf("REGISTER VERIFICATION STARTED\n");

    for(int i = 0; i < total; i++)
    {
        execute_transaction(test_sequence[i]);
    }

    printf("\nREGISTER VERIFICATION COMPLETED\n");

    return 0;
}
