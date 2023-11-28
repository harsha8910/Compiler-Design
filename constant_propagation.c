#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a 3-address code statement
struct ThreeAddressCode {
    int result;
    char op;
    int arg1;
    int arg2;
    bool isConstant; // Flag to indicate if the result is a constant
};

// Function to perform Constant Propagation and Folding
void performConstantPropagation(struct ThreeAddressCode* code, int numInstructions) {
    for (int i = 0; i < numInstructions; ++i) {
        // Check if both operands are constants
        if (code[i].isConstant && code[i].arg1 >= 0 && code[i].arg2 >= 0) {
            // Evaluate the expression at compile time
            switch (code[i].op) {
                case '+':
                    code[i].result = code[i].arg1 + code[i].arg2;
                    break;
                case '-':
                    code[i].result = code[i].arg1 - code[i].arg2;
                    break;
                case '*':
                    code[i].result = code[i].arg1 * code[i].arg2;
                    break;
                // Add more cases for other operators if needed
            }
            // Mark the result as a constant
            code[i].isConstant = true;
        }
    }
}

// Function to print the optimized code
void printOptimizedCode(struct ThreeAddressCode* code, int numInstructions, int flag) 
{
    if(flag==0)
    {
        for (int i = 0; i < numInstructions; ++i) {
            if (code[i].isConstant) {
                printf("t%d = %d %c %d\n", i, code[i].arg1, code[i].op, code[i].arg2);
            } else {
                printf("t%d = t%d %c", i, code[i].arg1, code[i].op);
                if (code[i].arg2 >= 0) {
                    printf(" t%d", code[i].arg2);
                }
                printf("\n");
            }
        }
    }
    else if(flag==1)
    {
        for (int i = 0; i < numInstructions; ++i) {
            if (code[i].isConstant) {
                printf("t%d = %d\n", i, code[i].result);
            } else {
                printf("t%d = t%d %c", i, code[i].arg1, code[i].op);
                if (code[i].arg2 >= 0) {
                    printf(" t%d", code[i].arg2);
                }
                printf("\n");
            }
        }
    }
    else
    {
        for (int i = 0; i < numInstructions; ++i) 
        {
            if (code[i].isConstant==false) 
            {
                switch (code[i].op) 
                {
                    case '+':
                        code[i].result = code[code[i].arg1].result + code[code[i].arg2].result;
                        break;
                    case '-':
                        code[i].result = code[code[i].arg1].result - code[code[i].arg2].result;
                        break;
                    case '*':
                        code[i].result = code[code[i].arg1].result * code[code[i].arg2].result;
                        break;
                }
            }
            printf("t%d = %d\n", i, code[i].result);
        }
    }
}

int main() {
    // Specify the number of instructions
    int numInstructions = 5;

    // Allocate memory for the array of 3-address code statements
    struct ThreeAddressCode* code = (struct ThreeAddressCode*)malloc(numInstructions * sizeof(struct ThreeAddressCode));

    // Initialize the array with sample 3-address code
    code[0] = (struct ThreeAddressCode) {0, '*', 9, 10, true};
    code[1] = (struct ThreeAddressCode) {1, '-', 3, 5, true};
    code[2] = (struct ThreeAddressCode) {2, '+', 0, 1, false};
    code[3] = (struct ThreeAddressCode) {3, '*', 6, 4, true};
    code[4] = (struct ThreeAddressCode) {4, '+', 3, 2, false};

    // Mark initial constants (if any)
    code[0].isConstant = true;
    code[1].isConstant = true;

    // Print the original code
    printf("Original Code:\n");
    printOptimizedCode(code, numInstructions, 0);

    // Perform Constant Propagation and Folding
    performConstantPropagation(code, numInstructions);

    // Print the optimized code
    printf("\nAfter constant folding:\n");
    printOptimizedCode(code, numInstructions, 1);

    printf("\nAfter constant propagation:\n");
    printOptimizedCode(code, numInstructions, 2);
    // Free allocated memory
    free(code);

    return 0;
}

