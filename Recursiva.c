#include <stdio.h> // Recursiva 

int f(int n) {
    if (n == 0) {
        return 0;
    } else if (n % 2 == 0) {
        return -f(n - 1) - 1;
    } else {
        return f(n - 1) + 1;
    }
}

void imprimirRelacao(int limite, int n) {
    if (n > limite) {
        printf("\n");
        return;
    }

    int resultado = f(n);
    printf("[%d, %d], ", n, resultado);

    imprimirRelacao(limite, n + 1);
}

int main() {
    int limite;

    printf("Informe o limite: ");
    scanf("%d", &limite);

    imprimirRelacao(limite, 0);

    return 0;
}