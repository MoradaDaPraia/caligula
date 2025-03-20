#include "stack.h"
#include <stdio.h>

void print_stack(const Stack *stack) {
    char buf[1024];

    printf("stack = %s\n", stack_show(stack, buf, "%c"));
}

int main(void) {
    Stack stack;
    char value;

    stack_init(&stack);

    stack_push(&stack, 'a');
    print_stack(&stack);

    stack_push(&stack, 'b');
    print_stack(&stack);

    stack_push(&stack, 'c');
    print_stack(&stack);

    stack_pop(&stack, NULL);
    print_stack(&stack);

    stack_pop(&stack, NULL);
    print_stack(&stack);

    stack_push(&stack, 'd');
    print_stack(&stack);

    stack_push(&stack, 'e');
    print_stack(&stack);

    stack_top(&stack, &value);
    printf("Top is '%c'.\n", value);

    stack_pop(&stack, NULL);
    print_stack(&stack);

    stack_pop(&stack, NULL);
    print_stack(&stack);

    stack_pop(&stack, NULL);
    print_stack(&stack);

    return 0;
}
