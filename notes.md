# Stacks

Stacks are structures where each item is stacked above each other.

The logic is simple, the first item that is inserted will be stacked above the
previous item inside the structure if it exists.

When we remove an item from the stack, the last item that was inserted is the first one removed,
with that in mind, we can say that stacks are a type of structure called "LIFO" which means
"last in first out"

## Basic operations

- Push(add_to_stack): Inserts an item at the **top** of the stack
- Pop(remove_from_strack): Removes an element from the **top** of the stack
- Clear(clear_stack): Removes all the elements of the stack
- Is full(is_stack_full): Verify if the stack is full, which means no more items can be added
- Is empty(is_stack_empty): Verify if the stack is empty, which means more items can be added
- Iteration(iterate_over_stack): Go over each element of the stack in the order as if they were removed but **without removing them**

### Custom operations

- List: Show stack values
