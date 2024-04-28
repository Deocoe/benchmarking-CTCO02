#include "algoritmos.h"

// Implementação do algoritmo de ordenação por inserção
void insertionSort(int vetor[], int n, int *comparacoes, int *trocas) {
		for (int i = 1; i < n; ++i) {
				int chave = vetor[i];
				int j = i - 1;
				*comparacoes += 1;
				while (j >= 0 && vetor[j] > chave) {
						vetor[j + 1] = vetor[j];
						j = j - 1;
						*comparacoes += 1;
						*trocas += 1;
				}
				vetor[j + 1] = chave;
		}
}

// Implementação do algoritmo de ordenação por seleção
void selectionSort(int vetor[], int n, int *comparacoes, int *trocas) {
		int i, j, min_idx;

		// Percorre todo o array
		for (i = 0; i < n-1; i++) {
				// Encontra o índice do menor elemento no array desordenado
				min_idx = i;
				for (j = i+1; j < n; j++) {
						(*comparacoes)++; // Incrementa o contador de comparações
						if (vetor[j] < vetor[min_idx]) {
								min_idx = j;
						}
				}
				// Troca o menor elemento com o primeiro elemento do array desordenado
				if(vetor[min_idx] < vetor[i]) {
					int temp = vetor[min_idx];
					vetor[min_idx] = vetor[i];
					vetor[i] = temp;
					(*trocas)++; // Incrementa o contador de trocas
				}
		}
}

// Função auxiliar para o merge sort que mescla duas sublistas ordenadas
void merge(int vetor[], int inicio, int meio, int fim, int *comparacoes, int *trocas) {
		int n1 = meio - inicio + 1;
		int n2 = fim - meio;

		int L[n1], R[n2];

		for (int i = 0; i < n1; i++)
				L[i] = vetor[inicio + i];
		for (int j = 0; j < n2; j++)
				R[j] = vetor[meio + 1 + j];

		int i = 0;
		int j = 0;
		int k = inicio;
		while (i < n1 && j < n2) {
				(*comparacoes)++;
				if (L[i] <= R[j]) {
						vetor[k] = L[i];
						i++;
				} else {
						vetor[k] = R[j];
						j++;
						(*trocas)++;
				}
				k++;
		}

		while (i < n1) {
				vetor[k] = L[i];
				i++;
				k++;
		}

		while (j < n2) {
				vetor[k] = R[j];
				j++;
				k++;
		}
}

// Implementação do algoritmo de ordenação merge sort
void mergeSort(int vetor[], int inicio, int fim, int *comparacoes, int *trocas) {
		if (inicio < fim) {
				int meio = inicio + (fim - inicio) / 2;
				mergeSort(vetor, inicio, meio, comparacoes, trocas);
				mergeSort(vetor, meio + 1, fim, comparacoes, trocas);
				merge(vetor, inicio, meio, fim, comparacoes, trocas);
		}
}

// Função de interface para o merge sort
void MergeSort(int vetor[], int n, int *comparacoes, int *trocas) {
		mergeSort(vetor, 0, n - 1, comparacoes, trocas);
}

// Função auxiliar para trocar dois elementos de um vetor
void troca(int* a, int* b, int* trocas) {
		int temp = *a;
		*a = *b;
		*b = temp;
		(*trocas)++;
}

// Função auxiliar para o quick sort que particiona o vetor em torno de um pivô
int particao(int vetor[], int inicio, int fim, int* comparacoes, int* trocas) {
		int pivo = vetor[fim];
		int i = inicio - 1;

		for (int j = inicio; j < fim; j++) {
				(*comparacoes)++;
				if (vetor[j] < pivo) {
						i++;
						troca(&vetor[i], &vetor[j], trocas);
				}
		}
		troca(&vetor[i + 1], &vetor[fim], trocas);
		return i + 1;
}

// Implementação do algoritmo de ordenação quick sort
void quickSort(int vetor[], int inicio, int fim, int* comparacoes, int* trocas) {
		if (inicio < fim) {
				int pi = particao(vetor, inicio, fim, comparacoes, trocas);

				quickSort(vetor, inicio, pi - 1, comparacoes, trocas);
				quickSort(vetor, pi + 1, fim, comparacoes, trocas);
		}
}

// Função de interface para o quick sort
void QuickSort(int vetor[], int n, int* comparacoes, int* trocas) {
		quickSort(vetor, 0, n - 1, comparacoes, trocas);
}

// Implementação do algoritmo de ordenação shell sort
void shellSort(int vetor[], int n, int* comparacoes, int* trocas) {
		for (int gap = n / 2; gap > 0; gap /= 2) {
				for (int i = gap; i < n; i++) {
						int temp = vetor[i];
						int j;
						(*comparacoes)++;
						for (j = i; j >= gap && vetor[j - gap] > temp; j -= gap) {
								(*comparacoes)++;
								vetor[j] = vetor[j - gap];
								(*trocas)++;
						}
						vetor[j] = temp;
				}
		}
}
