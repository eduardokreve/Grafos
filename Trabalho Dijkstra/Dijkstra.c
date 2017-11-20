#include <stdio.h>
#include <stdlib.h>
#define tam 7

int menor_valor(int matriz[][tam], int tab[][tam], int abertos[tam], int i) { //encontra o menor valor nao utilizado e maior que 0
    int menor = 100, pos;

    for(int j = 0; j  < tam; j++) { //anda pelas colunas para achar o vertice ligado com menor caminho
        if(matriz[i][j] < menor && matriz[i][j] > 0 && abertos[j] != -1) { //se aberto estiver como -1, ele ja foi utilizado
            menor = matriz[i][j];
            pos = j;
        }
    }
    return pos; //retorna a coluna (vertice ligado) com o menor caminho
}

void mapeia(int matriz[][tam], int abertos[tam], int tab[][tam]) { //mapeia e insere os valores na tabela
    int i, j, stop; //i -> linha, j-> coluna

    i = 0; //primeiro vertice que será procurado ligação

    for(stop = tam; stop > 0; stop--) { //a cada iteracao é preenchido a tab(matriz final de caminhos mais curtos)
        //acha qual coluna esta ligada com o vertice I
        for(j = 0 ; j < tam; j++) {
            if(matriz[i][j] != 0 && (tab[1][j] > matriz[i][j]+tab[1][i]) && abertos[j] != -1) { 
                tab[2][j] = i; //vert anterior
                tab[1][j] = tab[1][i] + matriz[i][j] ; //distancia do vertice + distancia do vertice achado
            }
        }

        abertos[i] = -1; //posicao i de abertos ja foi utilizada
        i = menor_valor(matriz,tab, abertos, i); // i recebe a linha na matriz, ou seja, qual o proximo vertice que ira
    }                                            //procurar o menor caminho
}

void menor_caminho(int tabela[][tam], char letras[tam]) { //mostra o menor caminho entre 0 e 20(A e Z)
    int pos = tam-1, i = 0;
    int vet[10]; //guarda os vertices

    printf("\nMenor Caminho:\n");

    while(pos != 0) {
        vet[i] = tabela[2][pos]; //guarda o vertice anterior
        pos = tabela[2][pos]; //recebe o vertice anterior para ser o proximo vertice a ser visitado
        i++;
    }

    printf("g ");
    for(int j = 0; j < i; j++) { //imprime o menor caminho
        printf("<-- %c ", letras[vet[j]]);
    }
    printf("\n");
}

void imprime_tabela(int tabela[][tam], char letras[tam]) { //imprime a matriz final de caminhos mais curtos

    for(int j = 0; j < tam; j++) {
        printf("__________________________________________________________\n\b");
        printf("Vertice :  %c\t", letras[tabela[0][j]]);
        printf("distancia :%d\t", tabela[1][j]);
        printf("vert.ante :%c\t", letras[tabela[2][j]]);
        printf("\n" );
    }
}

int main() {                   /*a, b, c,  d,  e,  f,  g*/
    int matriz[tam][tam] =     {{0, 7, 0,  5,  0,  0,  0}, //a
                                {7, 0, 8,  9,  7,  0,  0}, //b
                                {0, 8, 0,  0,  5,  8,  9}, //c
                                {5, 9, 0,  0, 15,  6,  0}, //d
                                {0, 7, 5, 15,  0,  8,  9}, //e
                                {0, 0, 0,  6,  8,  0, 11}, //f
                                {0, 0, 0,  0,  9, 11,  0}};//g

    int abertos[tam] = {0, 1, 2, 3, 4, 5, 6}; //usado para saber se o vertice ja foi utilizado

    int tabela[3][tam] = {{0, 1, 2, 3, 4, 5, 6}, //vertices
                         {0, 100, 100, 100, 100, 100, 100}, //distancia
                         {0, 0, 0, 0, 0, 0, 0}}; //vertice anterior

    char letras[tam] = {'a','b','c','d','e','f','g'}; //para trocar pelos numeros na hora de imprimir

   mapeia(matriz, abertos, tabela);
   imprime_tabela(tabela, letras);
   menor_caminho(tabela, letras);

   return 0;
}
