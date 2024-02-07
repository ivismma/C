#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // Biblioteca p/ diminuir velocidade da execu��o.

// Imprimir uma string percorrendo letras at� formar a letra atual at�
// que a string se forme por completo.


void exibeString(int tamAtual, char *str);

int main(void){
	char c, str[] = "hello world";
	const short int tam = strlen(str);
	char *str2 = malloc(tam * sizeof(char));
	
	for(int i = 0; i <= tam-1; ++i){
		for(c = 97; c <= 122; ++c){
			if (str[i] == ' ') c = ' '; // Checa se caracter atual � espa�o.
			exibeString(i, str2);
			printf("%c\n", c);
			usleep(45000); // Pausa de 45000 microssegundos.
			if(c == str[i]) break;
		}
		str2[i] = c;
	}
	free(str2);
	
	system("pause");
	return 0;
}

// fun��o p/ exibir string em seu tamanho **atual**.
void exibeString(int tamAtual, char *str){
	for(int i = 0; i < tamAtual; ++i)
		printf("%c", *(str+i));
}
