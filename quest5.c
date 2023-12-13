#include <stdio.h>

#define NUM_CIDADES 4

// Matriz de distâncias
int matrizDistancias[NUM_CIDADES][NUM_CIDADES] = {
    {0, 10, 20, 0},
    {10, 0, 30, 15},
    {20, 30, 0, 25},
    {0, 15, 25, 0}
};


void inserirDistancia(int cidade1, int cidade2, int distancia) {
    if (cidade1 >= 0 && cidade1 < NUM_CIDADES && cidade2 >= 0 && cidade2 < NUM_CIDADES) {
        matrizDistancias[cidade1][cidade2] = distancia;
        matrizDistancias[cidade2][cidade1] = distancia;     // A matriz é simétrica
    } else {
        printf("Cidades inválidas.\n");
    }
}

// Procedimento para contar quantas estradas ligam as cidades
void contarEstradas() {
    int numEstradas = 0;
    
    for (int i = 0; i < NUM_CIDADES; i++) {
        for (int j = i + 1; j < NUM_CIDADES; j++) {
            if (matrizDistancias[i][j] != 0) {
                numEstradas++;
            }
        }
    }
    
    printf("Total de estradas: %d\n", numEstradas);
}

// Procedimento para imprimir a matriz de distâncias
void imprimirMatriz() {
    printf("Matriz de Distancias:\n");
    
    for (int i = 0; i < NUM_CIDADES; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            printf("%d ", matrizDistancias[i][j]);
        }
        printf("\n");
    }
}

// Função recursiva para obter a distância entre duas cidades
int distanciaEntreCidades(int cidade1, int cidade2) {
    if (cidade1 >= 0 && cidade1 < NUM_CIDADES && cidade2 >= 0 && cidade2 < NUM_CIDADES) {
        return matrizDistancias[cidade1][cidade2];
    } else {
        return 0; 
    }
}

int main() {
    // Inserir distância entre cidades 0 e 3
    inserirDistancia(0, 3, 35);

    // Contar estradas
    contarEstradas();

    // Imprimir matriz 
    imprimirMatriz();

    
    int distancia = distanciaEntreCidades(1, 2);
    if (distancia > 0) {
        printf("Distancia entre cidade 1 e cidade 2: %d\n", distancia);
    } else {
        printf("Não há estrada entre cidade 1 e cidade 2.\n");
    }

    return 0;
}
