#include <stdio.h>
#include <stdlib.h>
#define tam 21
#define coluna_tab 4
#define branco 0
#define cinza 1
#define preto 2 /*Cores Definidas: 0 == branco, 1 == cinza, 2 == preto */

void gambi(int vetor[], int vert) { //é uma gambiarra mesmo
    int i = 0;

    while(1) {
        if(vetor[i] == -1) {
            vetor[i] = vert;
            break;
        }
        i++;
    }
}

/*Implementacao da funcao de busca em largura*/
void BFS(int tab[][tam], int matriz[][tam], int vertice, int vertices[]) { //faz o mapeamento
    int j = 0;

    for(j = 0; j < tam; j++) { //anda pelas colunas da matriz
        if(matriz[vertice][j] == 1 && tab[2][j] != preto) { //se é ligado e não foi visitado

            if(tab[2][j] == branco) tab[2][j] = cinza; //colore
            else tab[2][j] = preto;

            tab[0][j] = j; //distancia
            tab[1][j] = j-1; //vertice anterior

            gambi(vertices, j);
        }
    }
}

void procura(int tab[][tam], int matriz[][tam]) { //procura onde mapear
    int v_atual = 0;
    int aux[4] = {-1,-1,-1,-1};

    while(tab[3][tam] == branco) { //enquanto não pintar o ultimo vertice de outra cor
        BFS(tab, matriz, v_atual, aux);
        printf("%d %d %d %d\n", aux[0], aux[1], aux[2], aux[3]);
        
    }
}

void imprime_tabela(int tabela[][tam]) {
    printf("Vertices:  A B C D E F G H I J K L M N O P Q R S T Z\n");
    for(int i = 0; i < coluna_tab -1; i++) {

        if(i == 0)printf("distancia: ");
        else if(i == 1) printf("vert.ante: ");
        else if(i == 2) printf("Cor      : ");

        for(int j = 0; j < tam; j++) {
            printf("%d ", tabela[i][j]);
        }
        printf("\n");
    }


}
int main() {                 /*a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, z*/
    int matriz_a[tam][tam] = {{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//a
                              {1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//b
                              {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//c
                              {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},//d
                              {0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//e
                              {0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//f
                              {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//g
                              {0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//h
                              {0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//i
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},//j
                              {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},//k
                              {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},//l
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},//m
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},//n
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},//o
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},//p
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0},//q
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},//r
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1},//s
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},//t
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0}};//z

    int tabela[coluna_tab][tam] = {{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},//distancia
                                   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},//vert. anterior
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//cor
                                   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}};//vert. atual

    /*declaração do primeiro vertice(origem)
    tabela[0][0] = 0; //distancia
    tabela[2][0] = cinza; //pinta de cinza
    */
    procura(tabela, matriz_a); //funcao de busca em largura
    imprime_tabela(tabela);


    return 0;
}
