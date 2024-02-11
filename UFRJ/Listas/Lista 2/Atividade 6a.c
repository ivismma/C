/*
Q6 a) Implemente a vers�o recursiva da Quest�o 1 desta lista (m�todo de Newton).

Obs:
Entrada e sa�da: A entrada � um n�mero racional. A sa�da s�o 3 n�meros: (i) o n�mero lido, (ii) a
raiz quadrada calculada com a fun��o sqrt da biblioteca matem�tica <math.h> e (iii) a raiz quadrada
calculada com o m�todo que voc� escreveu.
*/
#include <math.h>
#include <stdio.h>

double metodoNewtonRec(double n, double x){
	return (fabs(x*x - n) < pow(10,-6))? x: metodoNewtonRec(n, x-(x*x - n)/(2*x));
}

int main(){
	double n;
	
	printf("Digite um numero para obter a raiz quadrada atrav�s do Metodo de Newton: ");
	scanf("%lf", &n);
	printf("\n N�mero inserido: %f", n);
	printf("\n Raiz quadrada pelo sqrt(): %f", sqrt(n));
	printf("\n Raiz quadrada pelo Metodo de Newton: %f", metodoNewtonRec(n, 10));
	
	return 0;
}
