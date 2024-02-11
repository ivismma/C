/*
Implemente a fun��o copiaString definida abaixo. Essa fun��o recebe duas strings
como entrada e copia a primeira string para a segunda, at� o tamanho m�ximo do espa�o de
mem�ria reservado para a segunda string
*/

/*PARTE 1*/

#include <stdio.h>

void copiaString(char str1[], char str2[], int max); // Assinatura da fun��o
void parte2_copiaString(char str1[], char str2[], int max); // Assinatura da fun��o (Parte 2 do exerc�cio)

/*Execute o programa abaixo para avaliar a sua implementa��o:*/
int main() {
	char palavra1[20], palavra2[10];
	puts("Digite uma palavra com ate 19 caracteres:");
	scanf("%19[^\n]", palavra1);
	copiaString(palavra1, palavra2, 9); // O Exerc�cio pediu para usar essa main, mas isso poderia ser melhorado usando sizeof(palavra2)-1 no lugar do 9.
	printf("%s\n%s\n", palavra1, palavra2);
	return 0;
}

void copiaString(char str1[], char str2[], int max){
	int i = 0;
	str2[max] = '\0'; // Inicializando com o caracter terminador da string.
	
	while(i < max) // �ndice anterior ao �ndice em que ser� colocado o '\0'.
		str2[i] = str1[i++];
	return; // void
}
// No gabarito, a sa�da esperada para "ola mundo ola" est� dita como "ola mund"
// Aparentemente est� errado, pois "ola mund" ainda possuiria mais 2 espa�os (1 para o 'o' e outro para '\0')
// Ent�o a resposta certa seria definitivamente "ola mundo" pois palavra2 tem tamanho 10 (vetor de 0-9).

/*PARTE 2 - "Agora inverta o tamanho das palavras: palavra1 com tamanho 10 e palavra2 com tamanho 20, e
verifique a corretude da sua implementa��o"*/

/*
int main() {
	char palavra1[10], palavra2[20];
	puts("Digite uma palavra com ate 9 caracteres:");
	scanf("%9[^\n]", palavra1);
	copiaString(palavra1, palavra2, 9); // O Exerc�cio pediu para usar essa main, mas isso poderia ser melhorado usando sizeof(palavra2)-1 no lugar do 9.
	printf("%s\n%s\n", palavra1, palavra2);
	return 0;
}

void copiaString(char str1[], char str2[], int max){
	int i = 0;
	str2[max] = '\0'; // Inserindo aracter nulo no fim da string com pr�-incremento.
	// max continua 9 pois a str1 (entrada) � menor do que a str 2, ent�o o terminador ter� que ser em str2[9].
	while(i < max) // �ndice anterior ao �ndice em que ser� colocado o '\0'.
		str2[i] = str1[i++];
	return; // void
}
*/
