#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void readline(char *buf, int len) {
    int i = 0;
    char current;
    while ((current = getchar()) != '\n') {
        if (i < len - 1) {
            buf[i] = current;
            i++;
        }
    }
    buf[i] = '\0';
}

bool validate_delimiters(const char *text) {
    Stack stack;
    int i;
    char value, expected;

    stack_init(&stack);

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == '(' || text[i] == '[' || text[i] == '{') {
            switch (text[i]) {
            case '(':
                expected = ')';
                break;
            case '[':
                expected = ']';
                break;
            case '{':
                expected = '}';
                break;
            }

            if (!stack_push(&stack, expected)) {
                fprintf(stderr,
                        "Cannot push more elements to the stack. Exiting...\n");
                exit(1);
            }
        } else if (text[i] == ')' || text[i] == ']' || text[i] == '}') {
            if (!stack_pop(&stack, &value)) {
                return false;
            }

            if (value != text[i]) {
                return false;
            }
        }
    }

    return true;
}

int main(void) {
    char buf[4096];
    int len = sizeof(buf) / sizeof(buf[0]);

    printf("Type in your expression: ");
    readline(buf, len);

    if (validate_delimiters(buf)) {
        printf("Your expresion delimiters are valid!\n");
    } else {
        printf("Your expresion delimiters are invalid.\n");
    }

    return 0;
}
