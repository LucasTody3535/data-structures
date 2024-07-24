#include <stdlib.h>

#include "../stack/interface.h"

typedef struct Stack StaticStack; // Type alias

StaticStack* createStaticStack(int quantity) {
    StaticStack* stack = malloc(sizeof(StaticStack));
    stack->top = -1;
    stack->data = calloc(quantity, sizeof(int8_t)); // When allocating arrays, always keep in mind the type of the pointer,
                                                                // if the pointer is int32_t, the sizeof allocation must be int32_t or above,
                                                                // otherwise, not enough space will be allocated, leading to undefined
                                                                // behavior
    int8_t* p = stack->data;
    stack->length = quantity;
    return stack;
}