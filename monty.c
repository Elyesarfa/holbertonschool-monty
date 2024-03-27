#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
*
*/

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(EXIT_FAILURE);
    }
    
    initStack();

    char opcode[10];
    int arg;
    int line_number = 0;

    while (fscanf(file, "%s", opcode) != EOF) {
        line_number++;
        if (strcmp(opcode, "push") == 0) {
            if (fscanf(file, "%d", &arg) != 1) {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            push(arg);
        } else if (strcmp(opcode, "pall") == 0) {
            pall();
        } else if (strcmp(opcode, "nop") == 0) {
            nop();
        } else {
            fprintf(stderr, "L%d: Unknown opcode: %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    return 0;
}
