/*Escreva um programa em C que leia do teclado um n�mero inteiro n e, a
partir da�, leia ent�o n inteiros positivos e, ao final, imprima a m�dia dos
pares e a m�dia dos �mpares. Se um inteiro negativo for lido:
? um aviso deve ser impresso na tela
? o la�o deve ser interrompido imediatamente
? as m�dias finais devem ser calculadas e apresentadas somente
com os n�meros at� ent�o coletados.
Utilize o comando de repeti��o �for�.
Teste os valores encontrados. Por exemplo, para N = 10, se os 10 n�meros
lidos do teclado forem {1,2,3,4,5,6,7,8,9,10}, ent�o teremos
�media dos pares = 6�
�media dos �mpares = 5�.*/

#include <stdio.h>
#include <locale.h>

int ler(char s[30]){
	int n;
	printf("%s", s);
	scanf("%d", &n);
	return n;
}

int checaNegativo(int x){
	if(x >= 0)
		return 1; // � positivo.
	return 0; // � negativo.
}

int checaPar(int x){
	if(x%2 == 0)
		return 1; // � par.
	return 0; // � �mpar.
}

int main(){
	setlocale(LC_ALL, "pt_BR.UTF-8");
	int pares, impares, qtdpares, qtdimpares, x, n = ler("Digite um valor n: ");
	float media1, media2;
	for(int i = 0; i < n; i++){
		x = ler("Digite um valor: ");
		if(!checaNegativo(x)){
			printf("Um n�mero negativo foi inserido e as m�dias ser�o calculadas somente at� aqui, programa interrompido.");
			break;
		}
		if(checaPar(x)){
			pares += x;
			qtdpares += 1;
		}
		else{
			impares += x;
			qtdimpares += 1;
		}
	}
	media1 = pares/qtdpares;
	media2 = impares/qtdimpares;
	
	printf("\nM�dia dos pares: %.2f", media1);
	printf("\nM�dia dos �mpares: %.2f", media2);

	return 0;
}
