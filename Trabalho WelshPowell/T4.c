#include <stdio.h>
#include <stdlib.h>
#define tam 11


void imprimeTabela(int tab[][tam]) {
    int i, j;

    printf("Vert: ");
    for (i = 0; i < 3; i++) { //linha

        if(i == 1) printf("Grau: ");
        else if(i ==2) printf("Cor:  ");

        for (j = 0; j < tam; j++) { //coluna
            printf("%d ", tab[i][j]);
        }

        printf("\n");
    }
    printf("_____________________________________\n");
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
        //define como zero a posicao para nao aparecer no prox laço
        tab[1][pos] = 0;
        //preenche a tabela temporaria
        temp[0][j] = pos;
        temp[1][j] = maior;
    }
    //passa os valores do vetor temp para a tab
    for (j = 0; j < tam; j++) {
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

//verifica com qual vertices o vertice N esta ligado
void pesqLigacao(int n, int vert[tam], int mat[][tam]) {
    int i, j = 0;

    for (i = 0; i < tam; i++) {
        if(mat[n][i] == 1) { //se esta ligado
            vert[j] = i;
            j++;
        }
    }
}

//anda pela matriz e vai preenchendo a tabela conforme alg. de Welsh & Powel
void WelshPowel(int mat[tam][tam], int tab[][tam]) {
    int i, j, cor = 1;
    int vertLig[tam] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};


    tab[2][0] = cor; //pinta o 1° vertice da lista com cor 1

    pesqLigacao(tab[0][0], vertLig, mat);



    for (j = 0; j < tam; j++) {

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

    /*1° PASSO */
    calculaGrau(matriz, tabela);
    imprimeTabela(tabela);
    /*2° PASSO */
    ordenaTabela(tabela);
    imprimeTabela(tabela);
    /*3° PASSO */
    WelshPowel(matriz, tabela);





    return 0;
}
