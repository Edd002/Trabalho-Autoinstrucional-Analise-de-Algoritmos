/*
 ============================================================================
 Name        : muro.c
 Author      : Eduardo Augusto Lima Pereira
 Version     :
 Copyright   : Your copyright notice
 Description : An�lise de Algoritmos - Autoinstrucional
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "mur.h"

int main(void) {
	setbuf(stdout, NULL);

	int tam = 3000;
	int posPartida = tam / 2;

	int* muro = criarMuro(tam);
	definirPosicaoPorta(muro, tam);
	//mostrarMuro(muro, tam);

	printf("ALGORITMO QUADR�TICO");
	printf("\nPosi��o da porta (algoritmo quadr�tico): %i", posicaoPortaQuadratico(muro, tam, posPartida));

	printf("\n\nALGORITMO LINEAR");
	printf("\nPosi��o da porta (algoritmo linear): %i", posicaoPortaLinear(muro, tam, posPartida));

	return EXIT_SUCCESS;
}
