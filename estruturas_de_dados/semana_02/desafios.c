/*
 * Código escrito pelo grupo do PCG:
 *
 * ANDREY ARTHUR SOUSA E SILVA
 * CAICK SANTOS BATISTA DE ARAÚJO
 * GUSTAVO PEREIRA DA SILVA
 * MARIA ALICE MELEK GERVASIO
 * RAFAEL MENEZES DE OLIVEIRA
 * VICTOR HUGO GALENO DE SOUSA
 */

#include <stdio.h>

int multiply(int a, int b) {
    if (b == 0) {
        return 0;
    }
    int result = a + multiply(a, b - 1);
    printf("%d = %d + m(%d, %d)\n", result, a, a, b - 1);
    return result;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

void hanoi(int disk, char src, char dest, char aux) {
    if (disk == 1) {
        printf("Move disk %d from %c to %c.\n", disk, src, dest);
        return;
    }
    hanoi(disk - 1, src, aux, dest);
    printf("Move disk %d from %c to %c.\n", disk, src, dest);
    hanoi(disk - 1, aux, dest, src);
}

int gcd(int a, int b) {
    if (b <= a && a % b == 0) {
        return b;
    }

    if (a < b) {
        return gcd(b, a);
    }

    return gcd(b, a % b);
}

void fibonacci_sequence(int previous, int current, int index, int target) {
    if (index == target) {
        return;
    }
    printf("%d ", current);
    fibonacci_sequence(current, previous + current, ++index, target);
}

void fibonacci(int n) {
    fibonacci_sequence(0, 1, 0, n);
    printf("\n");
}

int sum(int *vector, int len) {
    if (len == 0) {
        return 0;
    }
    return vector[0] + sum(&vector[1], --len);
}

int main(void) {
    int vector[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(vector) / sizeof(vector[0]);

    fibonacci(6);
    multiply(3, 5);

    return 0;
}
#include <stdio.h>

int multiply(int a, int b) {
    if (b == 0) {
        return 0;
    }
    int result = a + multiply(a, b - 1);
    printf("%d = %d + m(%d, %d)\n", result, a, a, b - 1);
    return result;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

void hanoi(int disk, char src, char dest, char aux) {
    if (disk == 1) {
        printf("Move disk %d from %c to %c.\n", disk, src, dest);
        return;
    }
    hanoi(disk - 1, src, aux, dest);
    printf("Move disk %d from %c to %c.\n", disk, src, dest);
    hanoi(disk - 1, aux, dest, src);
}

int gcd(int a, int b) {
    if (b <= a && a % b == 0) {
        return b;
    }

    if (a < b) {
        return gcd(b, a);
    }

    return gcd(b, a % b);
}

void fibonacci_sequence(int previous, int current, int index, int target) {
    if (index == target) {
        return;
    }
    printf("%d ", current);
    fibonacci_sequence(current, previous + current, ++index, target);
}

void fibonacci(int n) {
    fibonacci_sequence(0, 1, 0, n);
    printf("\n");
}

int sum(int *vector, int len) {
    if (len == 0) {
        return 0;
    }
    return vector[0] + sum(&vector[1], --len);
}

int main(void) {
    int vector[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(vector) / sizeof(vector[0]);

    fibonacci(6);
    multiply(3, 5);

    return 0;
}
#include <stdio.h>

int multiply(int a, int b) {
    if (b == 0) {
        return 0;
    }
    int result = a + multiply(a, b - 1);
    printf("%d = %d + m(%d, %d)\n", result, a, a, b - 1);
    return result;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

void hanoi(int disk, char src, char dest, char aux) {
    if (disk == 1) {
        printf("Move disk %d from %c to %c.\n", disk, src, dest);
        return;
    }
    hanoi(disk - 1, src, aux, dest);
    printf("Move disk %d from %c to %c.\n", disk, src, dest);
    hanoi(disk - 1, aux, dest, src);
}

int gcd(int a, int b) {
    if (b <= a && a % b == 0) {
        return b;
    }

    if (a < b) {
        return gcd(b, a);
    }

    return gcd(b, a % b);
}

void fibonacci_sequence(int previous, int current, int index, int target) {
    if (index == target) {
        return;
    }
    printf("%d ", current);
    fibonacci_sequence(current, previous + current, index + 1, target);
}

void fibonacci(int n) {
    fibonacci_sequence(0, 1, 0, n);
    printf("\n");
}

int sum(int *vector, int len) {
    if (len == 0) {
        return 0;
    }
    return vector[0] + sum(&vector[1], --len);
}

int main(void) {
    int vector[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(vector) / sizeof(vector[0]);

    printf("multiply(5, 2) = %d\n", multiply(5, 2));

    printf("\nfactorial(5) = %d\n", factorial(5));

    printf("\nfibonacci(6) = ");
    fibonacci(6);

    printf("\nhanoi = ");
    hanoi(3, 'A', 'B', 'C');

    printf("\ngcd(129, 30) = %d\n", gcd(129, 30));

    printf("\nsum([1, 2, 3, 4, 5, 6]) = %d\n", sum(vector, len));

    return 0;
}
