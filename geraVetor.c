#include "geraVetor.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* geraQuaseOrdenados(int tam, int porcentagem) {
		float percent = (float)porcentagem / 100.00; // Int porcentagem -> float percent
		int* vetor = (int*)malloc(tam * sizeof(int));
		int qtd_desordenados = (int)(tam * percent);

		// Preenche o vetor com dados ordenados, exceto na porcentagem desordenada
		for (int i = 0; i < tam - qtd_desordenados; ++i) {
				vetor[i] = i;
		}
		// Preenche os porcentagem restantes com valores aleatórios
		srand(time(0)); // Seed baseada no tempo atual
		for (int i = tam - qtd_desordenados; i < tam; ++i) {
				vetor[i] = rand() % (tam+1); //Números de 0 a tam
		}
		// Embaralha a porcentagem de elementos que deve ser desordenada
		for (int i = tam - 1; i >= tam - qtd_desordenados; --i) {
				int j = rand() % i;
				int temp = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = temp;
		}
		return vetor;
}

int* geraAleatorios(int tam, int semente) {
		srand(semente);
		int* vetor = (int*)malloc(tam * sizeof(int));
		for (int i = 0; i < tam; ++i) {
				vetor[i] = rand() % (tam+1); //Números de 0 a tam
		}
		return vetor;
}

int* geraOrdenados(int tam, int ordem) {
		int* vetor = (int*)malloc(tam * sizeof(int));
		if (ordem == 0) { // Ordem crescente
				for (int i = 0; i < tam; ++i) {
						vetor[i] = i;
				}
		} else { // Ordem decrescente
				for (int i = 0; i < tam; ++i) {
						vetor[i] = tam - i - 1;
				}
		}
		return vetor;
}
