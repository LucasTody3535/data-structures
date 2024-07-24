#include <stdio.h>
#include <math.h>
#include <stdint.h>

#include "./src/stacks/static-stack/interface.h"
#include "./src/stacks/stack/interface.h"

void staticStackExample() {
   int8_t stackCapacity = 16;
    printf("\n  Creating a static stack with a capacity of %i elements\n", stackCapacity);
    int8_t elementsToRemove = stackCapacity - 12;
    StaticStack* stack = createStaticStack(stackCapacity);

    printf("\n--------------------------------------------------------------------\n");

    printf("\n  Inserting values until the stack is filled\n");
    for(int8_t i = 1; i <= stackCapacity; i++) add_to_stack(stack, i);
    printf("  Is full(0 = No, 1 = Yes): %i\n", is_stack_full(stack));
    printf("  Is empty(0 = No, 1 = Yes): %i\n", is_stack_empty(stack));
    printf("  Listing...\n");
    list_stack(stack);

    //add_to_stack(stack, 5); // Causes overflow

    printf("\n\n--------------------------------------------------------------------\n");

    printf("\n  Removing %i elements\n", elementsToRemove);
    for(int8_t i = 0; i < elementsToRemove; i++) remove_from_stack(stack);
    printf("  Is full(0 = No, 1 = Yes): %i\n", is_stack_full(stack));
    printf("  Is empty(0 = No, 1 = Yes): %i\n", is_stack_empty(stack));
    printf("  Listing...\n");
    list_stack(stack);

    //add_to_stack(stack, 0x00); // Usage of invalid data

    printf("\n\n--------------------------------------------------------------------\n");

    printf("\n  Clearing stack\n");
    clear_stack(stack);
    printf("  Is full(0 = No, 1 = Yes): %i\n", is_stack_full(stack));
    printf("  Is empty(0 = No, 1 = Yes): %i\n", is_stack_empty(stack));
    printf("  Listing...\n");
    list_stack(stack);
    printf("\n");

    //remove_from_stack(stack); // Causes underflow
}

int main() {
    staticStackExample();
    return 0;
}