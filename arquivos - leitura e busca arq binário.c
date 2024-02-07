#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Escrever 7 n�meros e gravar em um arquivo bin�rio, em seguida
// inserir um n� n�mero p/ ver sua posi��o no arquivo bin�rio
// Esse c�digo ir� percorrer o arquivo e procurar onde est� posicionado o n� buscado.
// Se houver mais de um mesmo n�, a posi��o ser� o do primeiro encontrado.

int main(void){
	const int tam = 7;
	setlocale(LC_ALL, "Portuguese");
	int *v = malloc(tam * sizeof(int)); // Aloc. din�mica.
	if(v == NULL) return -1;
	
	printf("Digite 7 n�meros, separados por espa�o: ");
	for(int i = 0; i < tam; ++i) scanf("%d", v + i);
	
	// Escrita no arq. bin�rio:
	
	FILE *arq;
	if( !(arq = fopen("dados.dat", "wb")) ) return -2;
	else fwrite(v, sizeof(int), tam, arq);
	free(v);
	fclose(arq);
	
	// Busca e leitura no arq. bin�rio:
	
	int i = 1, busca, atual;
	printf("\n----- Consultar pos. do dado no arquivo -----\n");
	printf("Digite um dos n�meros que voc� digitou: ");
	scanf("%d", &busca);
	
	arq = fopen("dados.dat", "rb");
	while(fread(&atual, sizeof(int), 1, arq)){ // Enquanto leitura � v�lida..
		if(busca == atual) break;
		++i;
	}
	fclose(arq);
	if(busca == atual){
		printf("\nO n�mero buscado (%d) � o %d� valor do arquivo bin�rio.", busca , i);
		printf("\nSe houver n�meros repetidos, a posi��o encontrada � a do primeiro no arquivo bin�rio.");
	} 
	else printf("\nValor buscado (%d) n�o encontrado no arquivo bin�rio.", busca);
	
	return 0;	
}
