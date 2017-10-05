#include <stdio.h>
#include <stdlib.h>
#define tam 21
#define coluna_tab 4
#define branco 0
#define cinza 1
#define preto 2 /*Cores Definidas: 0 == branco, 1 == cinza, 2 == preto */

void emfileira(int vetor[], int vert) { //coloca na fila
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
void BFS(int tab[][tam], int matriz[][tam], int v_atual, int vertices[]) { //faz o mapeamento
    int j = 0;

    for(j = 0; j < tam; j++) { //anda pelas colunas da matriz
        if(matriz[v_atual][j] == 1 && tab[2][j] != preto && tab[0][j+2] == -1) { //se é ligado é preto

            if(tab[2][j] == branco) tab[2][j] = cinza; //colore
            else tab[2][j] = preto;

            tab[0][j] = j; //distancia
            tab[1][j] = j-1; //vertice anterior

            emfileira(vertices, j);
        }
    }
}

void desemfileira(int vetor[]) {
    int i = 7;

    while(i > 0) {
        vetor[i-1] = vetor[i];
        i--;
    }
}

void procura(int tab[][tam], int matriz[][tam]) { //procura onde mapear
    int v_atual = 0, i = 0;
    int fila[8] = {-1,-1,-1,-1,-1,-1,-1,-1}; //é o vertice atual

    while(i < tam) {
        desemfileira(fila);
        BFS(tab, matriz, v_atual, fila);
        for(int t = 0; t < 8; t++) {
            printf("%d ", fila[t]);
        }
        printf("\n");


        v_atual = fila[0];
        i++;
    }
}

void imprime_tabela(int tabela[][tam]) {
    for(int j = 0; j < tam; j++) {
        printf("Vertice  :%d\n", j);
        printf("distancia:%d\n", tabela[0][j]);
        printf("vert.ante:%d\n", tabela[1][j]);
        printf("Cor      :%d\n", tabela[2][j]);
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
