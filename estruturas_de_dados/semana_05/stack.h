#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 128
#include <stdbool.h>

typedef char StackItem;

typedef struct {
    int head;
    StackItem items[STACK_SIZE];
} Stack;

void stack_init(Stack *stack);

bool stack_push(Stack *stack, StackItem value);

bool stack_pop(Stack *stack, StackItem *value);

bool stack_top(const Stack *stack, StackItem *value);

bool stack_is_full(const Stack *stack);

bool stack_is_empty(const Stack *stack);

char *stack_show(const Stack *stack, char *buf, const char *format);

#endif
