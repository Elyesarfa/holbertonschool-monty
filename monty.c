#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file = fopen("bytecodes/nop_test.m", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(EXIT_FAILURE);
    }
    
    initStack();

    char opcode[10];
    int arg;

    while (fscanf(file, "%s", opcode) != EOF) {
        if (strcmp(opcode, "push") == 0) {
            if (fscanf(file, "%d", &arg) != 1) {
                fprintf(stderr, "Error: usage: push integer\n");
                exit(EXIT_FAILURE);
            }
            push(arg);
        } else if (strcmp(opcode, "pall") == 0) {
            pall();
        } else if (strcmp(opcode, "nop") == 0) {
            nop();
        } else {
            fprintf(stderr, "Unknown opcode: %s\n", opcode);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    return 0;
}
