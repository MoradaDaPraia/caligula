#include "stack.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void stack_init(Stack *stack) {
    stack->head = -1;
}

bool stack_push(Stack *stack, StackItem value) {
    if (stack_is_full(stack)) {
        return false;
    }

    stack->items[++(stack->head)] = value;
    return true;
}

bool stack_pop(Stack *stack, StackItem *value) {
    StackItem result;

    if (stack_is_empty(stack)) {
        return false;
    }

    result = stack->items[stack->head--];
    if (value != NULL) {
        *value = result;
    }
    return true;
}

bool stack_top(const Stack *stack, StackItem *value) {
    if (stack_is_empty(stack)) {
        return false;
    }

    if (value != NULL) {
        *value = stack->items[stack->head];
        return true;
    }

    return false;
}

bool stack_is_full(const Stack *stack) {
    return stack->head >= STACK_SIZE - 1;
}

bool stack_is_empty(const Stack *stack) {
    return stack->head == -1;
}

char *stack_show(const Stack *stack, char *buf, const char *format) {
    Stack new = *stack;
    char *current = buf;
    StackItem value;

    if (stack_is_empty(&new)) {
        sprintf(buf, "(empty)");
        return buf;
    }

    sprintf(current, "(");
    current += strlen(current);

    stack_pop(&new, &value);
    sprintf(current, format, value);
    current += strlen(current);

    sprintf(current, ")");
    current += strlen(current);

    while (stack_pop(&new, &value)) {
        sprintf(current, "<-");
        current += strlen(current);
        sprintf(current, format, value);
        current += strlen(current);
    }

    return buf;
}
