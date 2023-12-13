#include <stdio.h>

#define NUM_CIDADES 3

int grafo[NUM_CIDADES][NUM_CIDADES] = {
    {0, 450, 500},
    {0, 0, 0},
    {600, 0, 0}
};

// Função recursiva para calcular o comprimento do caminho entre duas cidades
int calcularCaminho(int cidadeA, int cidadeB) {
    if (cidadeA < 0 || cidadeB < 0 || cidadeA >= NUM_CIDADES || cidadeB >= NUM_CIDADES) {
        return -1; // Cidade inválida
    }
    
    if (cidadeA == cidadeB) {
        return 0; // A cidade de origem é igual à cidade de destino
    }

    int menorCaminho = -1;

    for (int i = 0; i < NUM_CIDADES; i++) {
        if (grafo[cidadeA][i] > 0) {
            int caminhoRestante = calcularCaminho(i, cidadeB);
            if (caminhoRestante >= 0) {
                int caminhoAtual = grafo[cidadeA][i] + caminhoRestante;
                if (menorCaminho == -1 || caminhoAtual < menorCaminho) {
                    menorCaminho = caminhoAtual;
                }
            }
        }
    }

    return menorCaminho;
}

// Função para verificar se há ciclos no grafo
int visitarCidade(int cidade, int visitadas[]) {
    if (visitadas[cidade] == 1) {
        return 1; // Cidade já visitada
    }
    if (visitadas[cidade] == -1) {
        return -1; // Ciclo detectado
    }

    visitadas[cidade] = -1;
    for (int i = 0; i < NUM_CIDADES; i++) {
        if (grafo[cidade][i] > 0) {
            if (visitarCidade(i, visitadas) == -1) {
                return -1;
            }
        }
    }
    visitadas[cidade] = 1;
    return 0;
}

int grauEntrada(int cidade) {
    int entrada = 0;
    for (int i = 0; i < NUM_CIDADES; i++) {
        if (grafo[i][cidade] > 0) {
            entrada++;
        }
    }
    return entrada;
}

int grauSaida(int cidade) {
    int saida = 0;
    for (int i = 0; i < NUM_CIDADES; i++) {
        if (grafo[cidade][i] > 0) {
            saida++;
        }
    }
    return saida;
}

int main() {
    int cidadeA, cidadeB;
    
    printf("Informe a cidade de origem (0, 1, 2): ");
    scanf("%d", &cidadeA);
    printf("Informe a cidade de destino (0, 1, 2): ");
    scanf("%d", &cidadeB);
    
    int comprimentoCaminho = calcularCaminho(cidadeA, cidadeB);
    if (comprimentoCaminho >= 0) {
        printf("O comprimento do caminho entre a cidade %d e a cidade %d é %d km.\n", cidadeA, cidadeB, comprimentoCaminho);
    } else {
        printf("Cidades inválidas.\n");
    }

    int visitadas[NUM_CIDADES] = {0};
    int ciclo = 0;
    for (int i = 0; i < NUM_CIDADES; i++) {
        if (visitadas[i] == 0) {
            if (visitarCidade(i, visitadas) == -1) {
                ciclo = 1;
                break;
            }
        }
    }

    if (ciclo) {
        printf("O grafo possui ciclos.\n");
    } else {
        printf("O grafo não possui ciclos.\n");
    }

    for (int i = 0; i < NUM_CIDADES; i++) {
        printf("Grau de entrada da cidade %d: %d\n", i, grauEntrada(i));
    }

    for (int i = 0; i < NUM_CIDADES; i++) {
        printf("Grau de saída da cidade %d: %d\n", i, grauSaida(i));
    }

    return 0;
}