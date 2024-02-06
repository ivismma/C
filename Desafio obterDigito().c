#include <stdio.h>

int obterDigito(int n, char letra);

int main(void){
	int numero, res;
	char letra;

	printf("Insira letra e digito, separados por espaco: ");
	scanf("%d %c", &numero, &letra);
	res = obterDigito(numero, letra);
	if(res != -1)
		printf("%d", res);
	else
		printf("Letra invalida inserida.");

	return 0;
}

int obterDigito(int n, char letra){
	int i, digito;
	n = (n < 0)? -n : n;    // Evitar retorno negativo.
	
	if(letra == 'u') 
		return n%10;        // A unidade do valor inserido � o que procuramos.
	else if(letra == 'd') 
		return n/10%10;     // Necess�rio pular um d�gito
	else if(letra == 'c') 
		i = n/100%10;       // Necess�rio pular dois d�gitos
	else if(letra == 'm') 
		i = n/1000%10;      // Necess�rio pular tr�s d�gitos
	else 
		return -1;          // Letra inv�lida.
	
}

/*

9. DESAFIO: Na Lista 2 - Quest�o 3, Tivemos um exerc�cio o qual, a partir de
um inteiro com 5 d�gitos, deveria ser impresso a unidade desse valor.
Dessa vez, crie uma fun��o que receba um inteiro e uma letra, o valor
inserido dever� possuir 4 d�gitos. Veja o que o programa dever� retornar
em cada caso:
Sugest�o de assinatura da fun��o: int obterDigito(int n, char letra);
Letra inserida - Retornar algarismo
�u�: - Retornar a unidade do valor.
�d� - Retornar a dezena do valor.
�c� - Retornar a centena do valor.
�m� - Retornar a unidade de milhar do valor.
Se outra letra for inserida, o programa dever� retornar -1.
S�o exemplos de entrada e sa�da da fun��o:
ENTRADA    SA�DA
1032, �d�    3
2024, �u�    4
2024, �c�    0
1723, �x�   -1

*/
