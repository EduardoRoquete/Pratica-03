#include <stdio.h> // Não recursiva 

int f(int n) {
    if (n % 2 == 0) {
        return -n / 2;
    } else {
        return n / 2 + 1;
    }
}

int main() {
    
    int limite;

    printf("Informe o limite: ");
    scanf("%d", &limite);

    for (int n = 0; n <= limite; n++) {
        int resultado = f(n);
        printf("[%d, %d], ", n, resultado);
    }

    printf("\n");

    return 0;
}
