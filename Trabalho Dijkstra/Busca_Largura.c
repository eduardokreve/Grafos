#include <stdio.h>
#include <stdlib.h>
#define tam 21
#define coluna_tab 4
 /*Cores Definidas*/
#define branco 0
#define cinza 1
#define preto 2


void mapeia(int tab[][tam], int matriz[][tam]) { //mapeia o grafo e insere os valores na tabela
    int stop, i = 0, j = 0, coluna = 0; //i -> linha, j-> coluna
	
    for(stop = 0; stop < tam-1; ) { //laço principal, para quando a tabela estiver preenchida

        for(j = 0; j < tam; j++) { //anda pelas colunas da matriz
            if(matriz[i][j] == 1 && tab[2][j] == branco) { //se é ligado e não foi visitado
                //atribui os valores na tabela
                tab[0][j] = tab[0][i] +1; //distancia
                tab[1][j] = i+1; //vertice anterior
                tab[2][j] = cinza; //colore
                tab[3][coluna++] = j+1; //vertice atual
            }
        }

        for(i = 0; i <= coluna; i++) {
            if(tab[3][i] != branco) { //se o vertice atual estiver preenchido
                j = i;
                i = tab[3][i] -1;
                stop++; //incremento do laço principal
                tab[2][i] = preto; //colore
                tab[3][j] = 0;
                break;
            }
        }
    }
}

void menor_caminho(int tabela[][tam], char letras[tam]) { //mostra o menor caminho entre 0 e 20(A e Z)
    int pos = tam-1, i = 0;
    int vet[10];

    printf("\nMenor Caminho:\n");
    while(pos >= 0) { //enquanto nao chegar ao inicio (começa do fim, posicao 20)
        vet[i] = tabela[1][pos]; //recebe o vertice anterior
        pos = tabela[1][pos] -1;
        i++; //quantidade de vertices que fazem parte do menor caminho
    }

    printf("z ");

    for(int j = 0; j < i-1; j++) { //imprime o menor caminho
        printf("<-- %c ", letras[vet[j]]-1);
    }
    printf("\n\n");
}

void imprime_tabela(int tabela[][tam], char letras[tam]) {

    for(int j = 0; j < tam; j++) {
        printf("__________________________________________________________\n\b");
        printf("Vertice :%c\t", letras[j]);
        printf("distancia :%d\t", tabela[0][j]);
        printf("vert.ante :%c\t", letras[tabela[1][j]]-1);
        if(tabela[2][j] == 0) printf("Cor :branco\t");
        else if(tabela[2][j] == 1) printf("Cor :cinza\t");
        else if(tabela[2][j] == 2) printf("Cor :preto\t");
        printf("\n" );
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

    int tabela[coluna_tab][tam] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//distancia
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//vert. anterior
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//cor
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};//vert. atual

    char letras[tam] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','z'};

    /*declaração do primeiro vertice(origem)*/
    tabela[2][0] = preto; //pinta de preto, porque não começa por ele

    mapeia(tabela, matriz_a); //funcao de busca em largura
    imprime_tabela(tabela, letras);
    menor_caminho(tabela, letras);

    return 0;
}
