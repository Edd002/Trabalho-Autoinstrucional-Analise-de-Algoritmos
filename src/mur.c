/*
 * mur.c
 *
 *  Created on: 3 de jun de 2019
 *      Author: n226804875
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "mur.h"

// Criar o muro: representado por um vetor com muitas posições
int* criarMuro(int tam) {
	int* muro = (int*) calloc(tam, sizeof(int*));
	return muro;
}

// Exibir todo o muro: elementos do vetor, sendo todos 0's com exceção de um único 1 que é a porta
void mostrarMuro(int* muro, int tam) {
	int i = 0;
	for (i = 0; i < tam; i++)
		printf("%i ", muro[i]);
	printf("\n");
}

// Exibir quantidade de passoa até a porta e total de passoas realizados
void mostrarPassos(int n, int nTotal) {
	printf("\nn (quantidade de passoas até a porta): %i", n);
	printf("\nnTotal (quantidade de passos realizados): %i", nTotal);
}

// Definir a posição da porta: posição randômica no vetor de onde o elemento 1 estará
void definirPosicaoPorta(int* muro, int tam) {
	time_t tempo;
	srand((unsigned) time(&tempo));
	muro[rand() % tam] = 1;
}

// Encontrar a posição da porta (quadrático): posição no vetor a partir de um ponto de partida
int posicaoPortaQuadratico(int* muro, int tam, int posPartida) {
	int n = 0; // Quantidade de passos da posição inicial até a porta
	int nTotal = 0; // Quantidade de passos total realizados
	int pos = posPartida;
	int p = 1;

	while (muro[pos] != 1) {
		// Andar para direita
		while (n < p) {
			n++;
			nTotal++;
			pos++;
			if (muro[pos] == 1) {
				mostrarPassos(n, nTotal);
				return pos;
			}
		}
		// Voltar para posição inicial
		while (pos != posPartida) {
			n--;
			nTotal++;
			pos--;
		}

		// Andar para esquerda
		while (n < p) {
			n++;
			nTotal++;
			pos--;
			if (muro[pos] == 1) {
				mostrarPassos(n, nTotal);
				return pos;
			}
		}
		// Voltar para posição inicial
		while (pos != posPartida) {
			n--;
			nTotal++;
			pos++;
		}

		p++;
	}

	mostrarPassos(n, nTotal);
	return pos;
}

// Encontrar a posição da porta (linear): posição no vetor a partir de um ponto de partida
int posicaoPortaLinear(int* muro, int tam, int posPartida) {
	int n = 0; // Quantidade de passos da posição inicial até a porta
	int nTotal = 0; // Quantidade de passos total realizados
	int pos = posPartida;
	int p = 1;
	int expP = 0;

	while (muro[pos] != 1) {
		// Andar para direita
		while (n < p) {
			n++;
			nTotal++;
			pos++;
			if (muro[pos] == 1) {
				mostrarPassos(n, nTotal);
				return pos;
			}
		}
		// Voltar para posição inicial
		while (pos != posPartida) {
			n--;
			nTotal++;
			pos--;
		}

		// Andar para esquerda
		while (n < p) {
			n++;
			nTotal++;
			pos--;
			if (muro[pos] == 1) {
				mostrarPassos(n, nTotal);
				return pos;
			}
		}
		// Voltar para posição inicial
		while (pos != posPartida) {
			n--;
			nTotal++;
			pos++;
		}

		expP++;
		p = pow(2, expP);
	}

	mostrarPassos(n, nTotal);
	return pos;
}
