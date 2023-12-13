#include <stdio.h>

#define NUM_CIDADES 3

int matrizAdjacencia[NUM_CIDADES][NUM_CIDADES] = {
    {0, 1, 2},
    {0, 0, 450},
    {0, 600, 0}
};

// Função recursiva para calcular o comprimento do caminho entre duas cidades
int calcularComprimentoCaminho(int cidadeOrigem, int cidadeDestino) {
    if (cidadeOrigem < 0 || cidadeOrigem >= NUM_CIDADES || cidadeDestino < 0 || cidadeDestino >= NUM_CIDADES) {
        return -1; 
    }

    if (cidadeOrigem == cidadeDestino) {
        return 0; 
    }

    int menorComprimento = -1;

    for (int i = 0; i < NUM_CIDADES; i++) {
        if (matrizAdjacencia[cidadeOrigem][i] != 0) {
            int comprimento = calcularComprimentoCaminho(i, cidadeDestino);
            if (comprimento != -1) {
                comprimento += matrizAdjacencia[cidadeOrigem][i];
                if (menorComprimento == -1 || comprimento < menorComprimento) {
                    menorComprimento = comprimento;
                }
            }
        }
    }

    return menorComprimento;
}

int temCiclos() {
    int visitado[NUM_CIDADES] = {0};

    for (int i = 0; i < NUM_CIDADES; i++) {
        if (!visitado[i]) {
            int pilha[NUM_CIDADES] = {0};
            int topo = -1;
            pilha[++topo] = i;

            while (topo >= 0) {
                int cidadeAtual = pilha[topo--];
                if (visitado[cidadeAtual] == 1) {
                    return 1; 
                }
                visitado[cidadeAtual] = 1;

                for (int j = 0; j < NUM_CIDADES; j++) {
                    if (matrizAdjacencia[cidadeAtual][j] != 0) {
                        if (!visitado[j]) {
                            pilha[++topo] = j;
                        }
                    }
                }
            }
        }
    }

    return 0; 
}


void calcularGrauEntrada() {
    for (int i = 0; i < NUM_CIDADES; i++) {
        int grauEntrada = 0;
        for (int j = 0; j < NUM_CIDADES; j++) {
            if (matrizAdjacencia[j][i] != 0) {
                grauEntrada++;
            }
        }
        printf("Grau de entrada de cidade %d: %d\n", i, grauEntrada);
    }
}


void calcularGrauSaida() {
    for (int i = 0; i < NUM_CIDADES; i++) {
        int grauSaida = 0;
        for (int j = 0; j < NUM_CIDADES; j++) {
            if (matrizAdjacencia[i][j] != 0) {
                grauSaida++;
            }
        }
        printf("Grau de saída de cidade %d: %d\n", i, grauSaida);
    }
}

int main() {
    int cidadeOrigem, cidadeDestino;

    
    printf("Informe a cidade de origem (0 a %d): ", NUM_CIDADES - 1);
    scanf("%d", &cidadeOrigem);

    printf("Informe a cidade de destino (0 a %d): ", NUM_CIDADES - 1);
    scanf("%d", &cidadeDestino);

    
    int comprimento = calcularComprimentoCaminho(cidadeOrigem, cidadeDestino);
    if (comprimento != -1) {
        printf("Comprimento do caminho entre cidade %d e cidade %d: %d km\n", cidadeOrigem, cidadeDestino, comprimento);
    } else {
        printf("Cidades inválidas ou não há caminho entre elas.\n");
    }

    
    if (temCiclos()) {
        printf("O grafo possui ciclos.\n");
    } else {
        printf("O grafo não possui ciclos.\n");
    }

    
    calcularGrauEntrada();

    calcularGrauSaida();

    return 0;
}
