#include <stdio.h>
#include <math.h>

// Exerc�cio 1 - Lista 4 (Estruturas de Repeti��o parte 2).

int potencia(int x, int y);
float somatorio(int n);

int main(void){
	int n;
	float res;
	
	printf("Digite o valor n para calcular o somatorio da Quest�o 1: ");
	scanf("%d", &n);
	res = somatorio(n);
	printf("%.3f", res);
	
	return 0;
}

// Somat�rio de i = 1 at� n de --> ( i�/(i+1) )
float somatorio(int n){
	float soma = 0;
	
	for(int i = 1; i <= n; ++i)
		soma += (float) (potencia(i,3))/(i+1);

	return soma;
}




// C�pia da fun��o do exerc�cio 6 - Lista 3.

int potencia(int x, int y){
	int resultado = 1;
	if(y == 0) return resultado;

	while(y--) // <--> while(i < y) declarando i = 0.
		resultado *= x;
	
	return resultado;
}
