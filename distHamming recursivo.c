#include <stdio.h>

/*
P1 antiga Prog I 2023.1

Quest�o 1) (3.0 pontos) Um caso particular da dist�ncia de Hamming (originalmente utilizada em textos)
� sua aplica��o sobre valores num�ricos, como segue:
A dist�ncia de Hamming entre dois n�meros naturais a e b, tais que a e b possuem a *mesma quantidade
de d�gitos*, � o n�mero m�nimo de substitui��es de algarismo necess�rias para igualar a e b.

Escreva um programa em C que calcule a dist�ncia de Hamming entre dois naturais, conforme as
especifica��es acima. Ambos os n�meros devem ser lidos do teclado. Seu programa dever�
necessariamente conter 3 fun��es, cujos nomes e prop�sitos s�o:
1) main � Onde ser� feita a coleta dos n�meros a e b e tamb�m a impress�o da dist�ncia de Hamming
entre eles.
2) numDig � Recebe um �nico natural de entrada, e retorna sua quantidade de d�gitos.
3) hamming � Recebe dois naturais de entrada, ambos com a mesma quantidade de d�gitos, e retorna a
dist�ncia de Hamming entre eles.
*/

short int numDig(int n); 
int hamming(int n1, int n2, int tam, int i);

int main(void){
	int n1;
	int n2;
	
	printf("Digite n1 e n2: ");
	scanf("%d %d", &n1, &n2);
	if(numDig(n1) != numDig(n2)) return 1;
	short int tam = numDig(n1);
	
	printf("\ndistHamming(%d,%d) = %d", n1, n2, hamming(n1,n2,tam,0));

	return 0;
}

short int numDig(int n){ 
	if(n == 0) return 1;
	n = (n < 0)? -n : n;
	
	short int soma = 1;
	while(n = n/10) 
		++soma;
		
	return soma;
}

int hamming(int n1, int n2, int tam, int i){
	if(i == tam) return 0;
	
	if(n1%10 != n2%10)
		return 1 + hamming(n1/10, n2/10, tam, i+1); 
	
	return hamming(n1/10, n2/10, tam, i+1); 
}
