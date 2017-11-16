#include <stdio.h>
#include <stdlib.h>
#define tam 8

//verifica qual o grau do vertice e sua posicao
void grauVertices(int matriz[][tam], int n, int vertices[tam]) {
	int i, j = 0;

	for(i = 0; i < tam; i++) {
		if(matriz[n][i] != 0) {
			vertices[j] = i; //recebe os vertices em que 'n' esta ligado
			j++;
		}
	}
}

//recebe as matrizes e o primeiro vertice          inic = orig
void prim(int matriz[][tam], int table[][tam], int inic) {
	int i, j, menorPeso, primeiro;

	while (1) {
		primeiro = 1;

		for (i = 0; i < tam; i++) { //percorre todos os vertices
			int vert[tam] = {-1,-1,-1,-1,-1,-1,-1,-1};

			if(table[1][i] != -1) { //e os vertices visitados, começando pelo 0
				grauVertices(matriz, i, vert); //pega o grau dos vertices que ja foram visitados

				



			}
			break;
		}
	break;
	}
}

int main() {                  //0  1  2  3  4  5  6  7
 	int matrizAdj[tam][tam] = {{0, 2, 0, 6, 5, 0, 0, 0},//0
							   {2, 0, 7, 7, 0, 0, 0, 0},//1
						   	   {0, 7, 0, 0, 6, 2, 0, 0},//2
						   	   {6, 7, 0, 0, 0, 0, 0, 0},//3
						   	   {5, 0, 6, 0, 0, 0, 4, 5},//4
						       {0, 0, 2, 0, 0, 0, 4, 6},//5
						   	   {0, 0, 0, 0, 4, 4, 0, 1},//6
						       {0, 0, 0, 0, 5, 6, 1, 0}};//7


					    //0  1   2   3   4   5   6   7
	int table[2][tam] = {{0, 10, 10, 10, 10, 10, 10, 10}, //dist
						 {0, -1, -1, -1, -1, -1, -1, -1}}; //vert anteriores


    prim(matrizAdj, table, 0);


	return 0;
}
