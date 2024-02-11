/*
Descri��o: Calcular a ra�z quadrada de um n�mero atrav�s do M�todo de Newton.
Entrada: N�mero (n) e um chute inicial de sua ra�z (x0).
Sa�da: A raiz quadrada de n pelo M�todo de Newton e pelo pow() da biblioteca <math.h>.
Defesa: O valor n deve ser um n�mero racional.
*/

#include <stdio.h>
#include <math.h>

double metodoDeNewton(double n){
	double x = 10, xantes; // x0 � igual a 10.
	 while(fabs(x-xantes) > pow(10,-6)){
	 	xantes = x;
		x = xantes - (pow(xantes,2)-n)/(2*xantes);
	 }
	return x;
}

void exibirResultado(double n, double res){
	printf("\nO n�mero inserido foi: %.3f\n", n);
	printf("O resultado da raiz quadrada utilizando o M�todo de Newton �: %f\n", res);
	printf("O resultado da raiz quadrada utilizando o pow() da math.h �: %f\n", pow(n,0.5));
}

int main(){
	double res,n;
	do{ // DEFESA
		printf("Digite um valor n racional: ");
		scanf("%lf", &n);
		if(n == 0)
			printf("ERRO - O N�mero deve ser diferente de zero.\n");
	} while (n == 0);	
	res = metodoDeNewton(n);
	exibirResultado(n, res);
	
	return 0;
}
