#include <stdio.h>
#include <stdlib.h>

#define tam 11
#define verm 1
#define azul 2
#define amar 3

void imprimeTabela(int tab[][tam]) {
    int i, j;

    for (i = 0; i < 2; i++) { //linha
        for (j = 0; j < tam; j++) { //coluna
            printf("%d ", tab[i][j]);
        }
        printf("\n\n");
    }
}

//ordena os dados da tabela em ordem decrescente de acordo a ordem alfabetica
void ordenaTabela(int tab[][tam]) {
    int i, j, maior, pos;
    int temp[2][tam]; //vetor temporario

    for (j = 0; j < tam; j++) {
        maior = pos = 0;
        for (i = 0; i < tam; i++) { //achar a posicao do maior valor
            if(tab[1][i] > maior) {
                maior = tab[1][i];
                pos = i;
            }
        }
        //define como zero
        tab[1][pos] = 0;
        //preenche a tabela temporaria
        temp[0][j] = pos;
        temp[1][j] = maior;
    }

    for (j = 0; j < tam; j++) { //passa os valores do vetor temp para a tab
        tab[0][j] = temp[0][j];
        tab[1][j] = temp[1][j];
    }
}

//preenche na tabela qual o grau de cada vertice
void calculaGrau(int mat[tam][tam], int tab[][tam]) {
    int i, j, grau;

    for (i = 0; i < tam; i++) { //linha
        grau = 0;
        for (j = 0; j < tam; j++) { //coluna
            if(mat[i][j] == 1) grau++;
        }
        tab[1][i] = grau;
    }
}

int main() {               //A  B  C  D  E  F  G  H  I  J  K
    int matriz[tam][tam] = {{0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0}, //A
                            {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, //B
                            {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, //C
                            {0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1}, //D
                            {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}, //E
                            {0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0}, //F
                            {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1}, //G
                            {1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1}, //H
                            {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0}, //I
                            {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1}, //J
                            {0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0}};//K

                         //A  B  C  D  E  F  G  H  I  J  K
    int tabela[3][tam] = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, //vertices
                          {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //grau
                          {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}};//cor


    calculaGrau(matriz, tabela);
    imprimeTabela(tabela);

    ordenaTabela(tabela);
    imprimeTabela(tabela);



    return 0;
}
