/*
Atividade 3: Escreva um programa em C que leia do teclado uma �nica string no formato
<c�digo> <pre�o> <desconto>
com: (1) c�digo de um produto (palavra que pode conter letras e n�meros); (2) pre�o do produto
(valor em reais); e (3) percentual de desconto do produto. Note que os 3 campos s�o separados por
um espa�o. O programa dever� calcular o novo valor do produto com o desconto dado, gerar uma
nova string no formatO <c�digo> <pre�o com desconto> e exibir essa string na tela.
Use as fun��es sscanf e sprintf.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){ // Vou utilizar Ponteiros na string para continuar praticando.
	char *str, *str2, codigo[20+1]; // str 2 = string final | c�digo com at� 20 caracteres.
	float preco, desconto;
	str = (char *) malloc(50 * sizeof(char));
	str2 = (char *) malloc(50 * sizeof(char));
	
	puts("Insira <c�digo> <pre�o> <desconto>"); 
	gets(str); // L� string.
	str = (char *) realloc(str, strlen(str)+1); // Realoca��o para otimiza��o de mem�ria
	
	// C�digo | pre�o | desconto, respeitando a quest�o --> em percentual, a ser convertido.
	sscanf(str, "%s %f %f", codigo, &preco, &desconto);
	if(!preco || !desconto || !codigo){ // Se uma das entradas � inv�lida, retorna -1.
		printf("Entrada inv�lida.");
		return -1;
	}
	desconto /= 100; // Desconto vira percentual. Ex: Insere 12 --> 12% de desconto (0.12).
	preco *= (1-desconto); // Alterando a vari�vel pre�o, considerando que seu dado antigo n�o ser� mais utilizada no futuro.
	
	sprintf(str2, "%s %.2f", codigo, preco); // Criando a string final (sa�da).
	str2 = (char *) realloc(str2, strlen(str2)+1); // Realoca��o para otimiza��o de mem�ria.
	printf("C�digo e pre�o com desconto aplicado: %s", str2);
	
	return 0;
}
