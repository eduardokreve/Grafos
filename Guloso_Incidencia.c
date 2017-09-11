#include <stdio.h>
#include <stdlib.h>

int totalPercorido=0;
int menorCaminho(int verticeAtual, int matriz[5][8]) { //achar o menor caminho do grafo
	int menor = 1000;
	int coluna = -1;
	
	for(int j = 0; j < 8; j++) { //vai achar o menor valor na linha
		if((matriz[verticeAtual][j] < menor) && (matriz[verticeAtual][j] > 0)) {
			menor = matriz[verticeAtual][j];
			coluna = j;			
		}
	}
//	printf("menor> %d\n", menor);
	return coluna; //retorna a coluna com o menor valor
}

int menorCaminhoB(int verticeAtual, int matriz[7][9]) { //achar o menor caminho do grafo
	int menor = 1000;
	int coluna = -1;
	
	for(int j = 0; j < 9; j++) { //vai achar o menor valor na linha
		if((matriz[verticeAtual][j] < menor) && (matriz[verticeAtual][j] > 0)) {
			menor = matriz[verticeAtual][j];
			coluna = j;			
		}
	}
//	printf("menor> %d\n", menor);
	return coluna; //retorna a coluna com o menor valor
}

int achaLinha(int linha, int coluna, int matriz[5][8]) { //acha a linha para a proxima procura no menor caminho
	int valor = matriz[linha][coluna];
	int proximoVertice=-1;
	for(int i = 0; i < 5; i++) {
		if(matriz[i][coluna] == valor*-1 && i!=linha){
			proximoVertice	=	i;
			break;	
		}else if(matriz[i][coluna] == valor&& i!=linha){
			proximoVertice	=	i;
			break;	
		} 
	}	
//	totalPercorido+=valor;
	return proximoVertice;
}

int achaLinhaB(int linha, int coluna, int matriz[7][9]) { //acha a linha para a proxima procura no menor caminho
	int valor = matriz[linha][coluna];
	int proximoVertice=-1;
	for(int i = 0; i < 7; i++) {
		if(matriz[i][coluna] == valor*-1 && i!=linha){
			proximoVertice	=	i;
			break;	
		}else if(matriz[i][coluna] == valor&& i!=linha){
			proximoVertice	=	i;
			break;	
		} 
	}	
//	totalPercorido+=valor;
	return proximoVertice;
}

int main() {
	int matriz[5][8] = {{30, 	0, 	0, 	20, 0,		0, 		-15, 0},
                     	{-30, 	50, 0, 	0, 	0, 		-10, 	0, 0},
                     	{0, 	0, 	0, 	0, 	-10, 	10, 	15, 5},
                     	{0, 	50, -30,0, 	0, 		0, 		0, -5},
                    	{0, 	0, 	30, -20,10, 	0, 		0, 0}};

	int matrizB[7][9] = {{2, 0, 12, 0, 0, 6, 0, 0, 0},
						 {-2, 1, 0, 0, 0, 0, 0, 0, 5},
						 {0, -1, 0, 40, 0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0, -6, 4, 0, 0},
						 {0, 0, -12, 0, 30, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0, 0, -4, 8, -5},
						 {0, 0, 0, -40, -30, 0, 0,-8,0}};
	

	int vLidos = 0, tVertices = 5;
	int proxVertice = 0, verticeAtual;
	int jaPassou[5];
	

	do {	
		verticeAtual = proxVertice; //linha
		jaPassou[vLidos] = verticeAtual;
		vLidos++;
		int coluna = menorCaminho(verticeAtual,matriz); //retorna a coluna que tem o menor valor	
		int valor = matriz[verticeAtual][coluna];
		if(vLidos!=tVertices)
		totalPercorido+=valor;
		proxVertice = achaLinha(verticeAtual, coluna, matriz); //linha, coluna, retorna o vertice		
	}while(vLidos < tVertices);

	
	printf("Vertices Lidos: %d\n",vLidos);
	for(int i=0;i<5;i++){
		printf("\njaPassou[%d] -> %d	",i, jaPassou[i]+1);
	}
	printf("\n\nTotal percorido: %d\n",totalPercorido);
	
	/*       Segundo grafo             */
	
	int Passou[7];
	totalPercorido = 0;
	vLidos = 0; 
	tVertices = 7;
	proxVertice = 0;
	verticeAtual = 0; 
	
	
	do {	
		verticeAtual = proxVertice; //linha
		Passou[vLidos] = verticeAtual;
		vLidos++;
		if(vLidos == 4) break;
		
		int coluna = menorCaminhoB(verticeAtual,matrizB); //retorna a coluna que tem o menor valor	
		int valor = matrizB[verticeAtual][coluna];
		if(vLidos!=tVertices)
			totalPercorido+=valor;
		proxVertice = achaLinhaB(verticeAtual, coluna, matrizB); //linha, coluna, retorna o vertice	
		
	}while(vLidos < tVertices);

	
	printf("Vertices Lidos: %d\n",vLidos);

	for(int i=0;i<vLidos;i++){
		printf("\njaPassou[%d] -> %d	",i, Passou[i]+1);
	}
	printf("\n\nTotal percorido: %d\n",totalPercorido);

	return 0;
}
