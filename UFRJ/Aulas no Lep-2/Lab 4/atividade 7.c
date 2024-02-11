/*Atividade 7 - o desvio incondicional �continue�.
Fa�a a seguinte modifica��o na Atividade 6:
Se um inteiro negativo for lido:
? um aviso deve ser impresso na tela;
? o programa ent�o avan�ar� imediatamente para a pr�x itera��o,
sem produzir incremento (para que um total de n n�meros v�lidos ainda
possa ser lido!);
? se, por�m, um n�mero negativo ocorrer 3 vezes, ent�o o la�o deve
ser interrompido imediatamente, e as m�dias apresentadas com os
n�meros at� ent�o coletados.*/

#include <stdio.h>
#include <locale.h>

int ler(char s[30]){
	int n;
	printf("%s", s);
	scanf("%d", &n);
	return n;
}

int ler3x(char s[30]){
	int tries; // tentativas.
	int x = ler(s);
	for(int i = 1; i < 3; i++){
		if(!checaNegativo(x))
			ler("Por favor, digite um n�mero positivo: ");
		else
			return x; // Inseriu um n�mero positivo, OK! Retorna o valor inserido.
	}
	return -1; // N�o inseriu um n�mero positivo.
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
		x = ler3x("Digite um valor: "); // Resolver problema do negativo contando
		if(x < 0){
			printf("Um n�mero negativo foi inserido 3 vezes e as m�dias ser�o calculadas somente at� aqui, programa interrompido.");
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
