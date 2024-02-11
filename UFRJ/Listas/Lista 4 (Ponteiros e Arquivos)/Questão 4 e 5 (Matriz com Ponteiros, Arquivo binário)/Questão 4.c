/*
Quest�o 4) Escreva um programa que receba do teclado a dimens�o N e os valores de uma matriz
quadrada de float, N <= 10, e salve essas informa��es em um arquivo bin�rio.
*/

#include <stdio.h>
#include <stdlib.h>

// Minhas observa��es:
// Na matriz com ponteiros, o primeiro for() incrementa N ao i para tratar os blocos de dimens�es, j percorre o interior dos blocos.
// Pra entender melhor, � s� pensar em uma sequ�ncia de aloca��es na heap. Se a matriz for 3x3, por exemplo:
// M[0][0], M[0][1], M[0][2], M[1][0], M[1][1]... com ponteiros: *(M + 0 + 0), *(M + 0 + 1), *(M + 0 + 2), *(M + 3 + 0), ...
// Repare que no �ltimo n�o se faz *(M + 1 + 0) porque isso daria no elemento M[0][1], ou seja, sempre incrementa-se a dimens�o ao N.
// Mas � importante levar em conta que esse exerc�cio trata-se de matrizes quadradas (matriz NxN).

void preencheMatriz(float *M, int d){
	printf("Digite do teclado %d numeros separados por espaco para preencher a matriz:\n", d*d);
	for(int i = 0; i < d*d; i += d)
		for(int j = 0; j < d; ++j) 
			scanf("%f", (M + i + j));
}

void exibeMatriz(float *M, int d){
	for(int i = 0; i < d*d; i += d){
		for(int j = 0; j < d; ++j){
			printf("%.1f  ", *(M + i + j) );
		}
		printf("\n");
	}
	return;
}

int main(){
	int N;
	float *pM; // Ponteiro para Matriz.
	
	do{
		printf("Digite o tamanho N (de dimensoes) da Matriz quadrada M, N deve ser de ate 10: ");
		scanf("%d", &N);
	} while(N < 1 || N > 10);
	
	// Aloca��o do Ponteiro da Matriz
	pM = (float *) malloc(N * N * sizeof(float));
	if(!pM){
		printf("Erro na alocacao de memoria.");
		return -1;
	}
	// Inserir os elementos no teclado
	
	preencheMatriz(pM, N);
	exibeMatriz(pM, N);
	
	// Armazenar em um arquivo bin�rio
	FILE *arquivo;
	arquivo = fopen("dados.dat", "wb");
	
	if(!arquivo){
		printf("Erro na criacao do arquivo.");
		return -1;
	}
	fwrite(pM, sizeof(float), N*N, arquivo);
	
	free(pM); // Liberacao de memoria do ponteiro da matriz.
	fclose(arquivo); // Fechamento do arquivo.
	printf("Dados salvos.");
	
	return 0;
}
