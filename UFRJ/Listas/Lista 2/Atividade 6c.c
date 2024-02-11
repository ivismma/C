/*
c) Vimos que a soma dos n primeiros termos de uma s�rie harm�nica produz o chamado
n�mero harm�nico Hn, definido abaixo

Imagem: Somat�rio de (k = 1 para n) de 1 / k.

Escreva um programa em C que calcula recursivamente o n�mero Hn, para algum N de
entrada tal que N <= 100. Teste se os valores encontrados pelo seu programa est�o corretos. S�o
exemplos de sa�das esperadas:
*/
#include <stdio.h>

double serieHarmonica(int n){
	return (n == 1)? 1:1.0/n + serieHarmonica(n - 1);
}	

int main(){
	int n;
	
	printf("Digite um n�mero para obter sua s�rie harm�nica: ");
	scanf("%d", &n); printf("%lf", serieHarmonica(n));
	
	return 0;
}
