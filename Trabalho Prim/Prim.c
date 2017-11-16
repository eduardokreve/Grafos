#include <stdio.h>
#include <stdlib.h>
#define tam 8


int contGrau(int matriz[][tam], int vertice) { //contar qual o grau de cada vertice
	int i, num = 0;

	for(i = 0; i < tam; i++) {
		if(matriz[vertice][i] != 0) num++;
	}
	return num;
}

                                               //inic = orig
void prim(int matriz[][tam], int table[][tam], int inic) { //recebe as matrizes e o primeiro vertice
	int i, j, menorPeso, primeiro;

	while (1) {
		primeiro = 1;

		for (i = 0; i < tam; i++) {
			if(table[1][i] != -1) {
				int grau = contGrau(matriz, i);

				for(j = 0; j < grau; j++) {

				}
			}
		}
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
	int table[2][tam] = {{0, 10, 10, 10, 10, 10, 10, 10},
						 {0, -1, -1, -1, -1, -1, -1, -1}};


    prim(matrizAdj, table, 0);


	return 0;
}
