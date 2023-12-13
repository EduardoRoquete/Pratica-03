#include <stdio.h>

int s(int n) {
    return n + 1;
}

int main() {
    int i;

    printf("Informe o valor de 'i': ");
    scanf("%d", &i);

    int MQ[i + 1][i + 1];

    // Inicialização da base MQ0 = { [0, 1] }
    MQ[0][0] = 1;

    // Construção não recursiva do conjunto MQ
    for (int j = 1; j <= i; j++) {
        for (int k = 0; k <= j; k++) {
            MQ[j][k] = MQ[j - 1][k];
            if (k > 0) {
                MQ[j][k] |= MQ[j - 1][k - 1];
            }
        }
    }

    // Imprimindo o conjunto MQ
    for (int j = 0; j <= i; j++) {
        printf("MQ%d = {", j);
        for (int k = 0; k <= i; k++) {
            if (MQ[j][k] == 1) {
                printf(" [%d, %d],", k, j + 1);
            }
        }
        printf(" }\n");
    }

    return 0;
}