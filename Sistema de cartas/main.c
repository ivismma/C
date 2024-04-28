#include "header.h"

short int qtdJogadores;
short int cartasViradas = 0; // mesa n�o usada aqui.

int main(void){
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite quantidade de jogadores: ");
	scanf("%hd", &qtdJogadores);
	if(qtdJogadores < 1 || qtdJogadores > 6){
		printf("M�n 1 | M�x 6");
		return 10;
	}
	
	// Baralho auxiliar (uasdo para embaralhar)
	Carta *aux = malloc(52 * sizeof(Carta));
	iniciarVet(aux);
	
	// Baralho principal:
	Pilha *baralho_topo = NULL;
	inicializarBaralho(&baralho_topo);
	
	// Alocando jogadores e a mesa.
	Jogador *jogador = malloc(qtdJogadores * sizeof(Jogador));
	Mesa *mesa = malloc(sizeof(Mesa));
	
	// Rodada 1 (simula��o):
	embaralhar(&baralho_topo, aux);
	msg1(true);
	distribuirCartas(&baralho_topo, jogador);
	exibirJogadores(jogador);
	
	//////////////////////////////////
	recolherCartas(&baralho_topo, *mesa, jogador);
	msg1(false);
	msg1(true);
	
	// Rodada 2 (simula��o):
	embaralhar(&baralho_topo, aux);
	distribuirCartas(&baralho_topo, jogador);
	exibirJogadores(jogador);
	
	//////////////////////////////////
	msg1(false);
	recolherCartas(&baralho_topo, *mesa, jogador);
	
	// Libera��o de mem�ria.
	baralho_topo = esvaziarPilha(baralho_topo);
	free(aux);
	free(mesa);
	free(jogador);
	
	system("pause");
	return 0;
}
