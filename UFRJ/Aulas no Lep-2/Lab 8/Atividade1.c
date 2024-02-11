/*Atividade 1: Na Matem�tica, dados dois vetores v e w (com in�cio na origem) em um espa�o de N
dimens�es (RN), o produto interno desses dois vetores � o escalar denotado por v.w

definido por:
� v.w = v1 * w1 + v2 * w2, se v = (v1, v2) e w = (w1, w2) s�o vetores no espa�o de duas dimens�es;
� v.w = v1 * w1 + v2 * w2 + v3 * w3, se v = (v1, v2, v3) e w = (w1, w2, w3) s�o vetores no espa�o de
tr�s dimens�es;
...e assim sucessivamente.
Exemplo: (-5, 2) . (3, 7) = -5*3 + 2*7 = -15 + 14 = -1
Tarefa:
1) Escreva uma fun��o para calcular o produto interno de dois vetores de mesma dimens�o N,
sendo 0 < N <= 10. A fun��o dever� receber os dois vetores e sua dimens�o como
par�metros de entrada, e retornar o produto interno calculado.
2) Escreva um programa para testar a sua fun��o usando os casos de teste abaixo. Leia do
teclado a dimens�o e o conte�do dos dois vetores.*/

#include <stdio.h>

float produtoInterno(float v[], float w[], int qtd){
	float soma = 0;
	for(int i = 0; i < qtd; ++i){
		soma += (v[i])*(w[i]);
	} return soma;
}

int main(){
	
	short int dimensoes, i = 0;
	float valor, res;
	do{
		printf("Digite a quantidade de dimens�es (Entre 1 e 10) --> ");
		scanf("%d", &dimensoes);
	} while(dimensoes <= 0 && dimensoes > 10);
	float v[dimensoes], w[dimensoes]; printf("\n");
	
	while(i < dimensoes){
		printf("Insira o %d-n-esimo elemento do vetor v: ", i+1);
		scanf("%f", &v[i]);
		++i;
	} i = 0; printf("\n");
	while(i < dimensoes){
		printf("Insira o %d-n-esimo elemento do vetor w: ", i+1);
		scanf("%f", &w[i]);
		++i;
	}

	res = produtoInterno(v,w,dimensoes);
	printf("O resultado do produto interno entre os vetores �: %.2f", res);
	return 0;
}
