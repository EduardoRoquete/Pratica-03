#include <stdio.h>

int s(int n) {
    return n + 1;
}

void menorQue(int i) {
    int j, k;

    int MQ[ i +1 ][i + 1];

    // Inicialização da base MQ0 = { [0, 1] }
    MQ[0][0] = 1;

    // Construção recursiva do conjunto MQ
    for (j = 1; j <= i; j++) {
        for (k = 0; k < j; k++) {
            MQ[j][k] = MQ[j - 1][k];
            MQ[j][s(k)] = 1;
        }
    }

    // Imprimindo o conjunto MQ
    for (j = 0; j <= i; j++) {
        printf("MQ%d = {", j);
        for (k = 0; k <= i; k++) {
            if (MQ[j][k] == 1) {
                printf(" [%d, %d],", k, j + 1);
            }
        }
        printf(" }\n");
    }
}

int main() {
    int i;

    printf("Informe o valor de 'i': ");
    scanf("%d", &i);

    menorQue(i);

    return 0;
}
