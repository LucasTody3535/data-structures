#include <stdint.h>

struct Stack {
    int8_t top;
    int8_t length;
    int8_t* data; // This pointer will point to the first element in the array
    // int data[]; this is a flexible array member
};

// The NULL(0x00) will be the value used to determine if a index is empty or not
int8_t is_stack_full(struct Stack* stack);
int8_t is_stack_empty(struct Stack* stack);

void list_stack(struct Stack* stack);
void clear_stack(struct Stack* stack);

int8_t remove_from_stack(struct Stack* stack);
void add_to_stack(struct Stack* stack, int8_t value);
