#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "./interface.h"

enum STACK_ERROR_CODES {
    STACK_OVERFLOW_ERROR = 1,
    STACK_UNDERFLOW_ERROR = 2,
    STACK_DATA_ERROR = 3
};

const int8_t EMPTY = 0x00;

struct Stack Stack;

int8_t is_stack_full(struct Stack* stack) { return stack->length - 1 == stack->top; }
int8_t is_stack_empty(struct Stack* stack) { return stack->top == -1; }

void clear_stack(struct Stack* stack) {
    stack->top = -1;
    for(int8_t i = 0; i < stack->length; i++) stack->data[i] = EMPTY;
}

void add_to_stack(struct Stack* stack, int8_t value) {
    if(is_stack_full(stack)) {
        fprintf(stderr, "\n\n >>>> Overflow detected(code: %i)\n", STACK_OVERFLOW_ERROR);
        exit(STACK_OVERFLOW_ERROR);
    }
    else if(value == EMPTY) {
        fprintf(stderr, "\n\n >>>> Usage of 0(0x00) detected(code: %i)\n", STACK_DATA_ERROR);
        exit(STACK_DATA_ERROR);
    }
    stack->top++;
    stack->data[stack->top] = value;
}

int8_t remove_from_stack(struct Stack* stack) {
    if(is_stack_empty(stack)) {
        fprintf(stderr, "\n\n >>>> Underflow detected(code: %i)\n", STACK_UNDERFLOW_ERROR);
        exit(STACK_UNDERFLOW_ERROR);
    }
    int8_t removed = stack->data[stack->top];
    stack->data[stack->top] = EMPTY;
    stack->top--;
    return removed;
}

void list_stack(struct Stack* stack) {
    for(int8_t i = 0; i < stack->length; i += 4) {
        printf("   %i) %i | %i) %i | %i) %i | %i) %i\n",
            i + 1,
            stack->data[i],
            i + 2,
            stack->data[i + 1],
            i + 3,
            stack->data[i + 2],
            i + 4,
            stack->data[i + 3]
        );
    }
}

void iterate_over_stack(struct Stack* stack) {
    for(int8_t i = stack->top; i > -1; i--) printf("\n  Value at %i: %i", i, stack->data[i]);
}
