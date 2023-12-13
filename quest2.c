#include <stdio.h>

// Função para calcular o sucessor de um número
int sucessor(int n) {
    return n + 1;
}

// Função para calcular a soma de dois números de forma recursiva
int soma(int m, int n) {
    if (n == 0) {
        return m;
    } else {
        return soma(m, sucessor(n - 1));
    }
}

int main() {
    int m, n;

    printf("Digite o primeiro numero: ");
    scanf("%d", &m);

    printf("Digite o segundo numero: ");
    scanf("%d", &n);

    int resultado = soma(m, n);

    printf("A soma de %d e %d e: %d\n", m, n, resultado);

    return 0;
}