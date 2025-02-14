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
#include <stdlib.h>
#include <string.h>

float scalar(float* a, float* b) {
    float sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}

void vectorial(float* result, float* a, float* b) {
    result[0] = a[1] * b[2] - a[2] * b[1];
    result[1] = -(a[0] * b[2] - a[2] * b[0]);
    result[2] = a[0] * b[1] - a[1] * b[0];
}

void print_vector(float* vector) {
    printf("(");
    int i;
    for (i = 0; i < 3; i++) {
        printf("%g", vector[i]);
        if (i != 2) {
            printf(", ");
        }
    }
    printf(")\n");
}

int main(void) {
    float a[3];
    float b[3];

    printf("Insira os valores do vetor A: ");
    int i;
    for (i = 0; i < 3; i++) {
        scanf("%f", &a[i]);
    }

    printf("Insira os valores do vetor B: ");
    for (i = 0; i < 3; i++) {
        scanf("%f", &b[i]);
    }

    float result[3];
    vectorial(result, a, b);

    printf("\nProduto escalar  = %g\nProduto vetorial = ", scalar(a, b));
    print_vector(result);

    return 0;
}