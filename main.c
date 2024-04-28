#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algoritmos.h"
#include "geraVetor.h"

// Função para limpar o console
void limparConsole() {
		// Limpar o console no Windows ou Linux/Mac
		#ifdef _WIN32
				system("cls");
		#else
				system("clear");
		#endif
}

int main() {
		int semente = 0;

		// Define os algoritmos
		void (*algoritmos[])(int[], int, long long int*, long long int*) = {insertionSort , selectionSort, MergeSort, QuickSort, shellSort};
		char *nomes_algoritmos[] = {"Insertion Sort" , "Selection Sort", "Merge Sort", "Quick Sort", "Shell Sort"};
		int num_algoritmos = sizeof(algoritmos) / sizeof(algoritmos[0]);

		// Define os métodos de geração de vetor
		char *nomes_metodos[] = {"Aleatorio", "Quase Ordenado", "Ordenado"};
		int num_metodos = sizeof(nomes_metodos) / sizeof(nomes_metodos[0]);

		int opcao;
		do {
				printf("Escolha o algoritmo:\n0 - Insertion Sort\n1 - Selection Sort\n2 - Merge Sort\n3 - Quick Sort\n4 - Shell Sort\n-1 para sair: ");
				scanf("%d", &opcao);
				if (opcao >= 0 && opcao < num_algoritmos) {
						printf("\nEscolha o metodo de geracao de vetor:\n0 - Aleatorio\n1 - Quase Ordenado\n2 - Ordenado: ");
						int metodo;
						scanf("%d", &metodo);

						if (metodo >= 0 && metodo < num_metodos) {
								long long int tamanho;
								if (metodo == 1) {
										printf("Escolha a porcentagem de Desordem: ");
										int porcentagem;
										scanf("%d", &porcentagem);
										printf("Escolha o tamanho do vetor: ");
										scanf("%lld", &tamanho);
										int *vetor = geraQuaseOrdenados(tamanho, porcentagem);
										long long int comparacoes = 0, trocas = 0;
										clock_t inicio = clock();
										algoritmos[opcao](vetor, tamanho, &comparacoes, &trocas);
										clock_t fim = clock();
										double tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
										printf("\nAlgoritmo: %s\n", nomes_algoritmos[opcao]);
										printf("Metodo de geracao: %s (Porcentagem de Desordem: %d%%)\n", nomes_metodos[metodo], porcentagem);
										printf("Tamanho do vetor: %lld\n", tamanho);
										printf("Comparacoes: %lld\n", comparacoes);
										printf("Trocas: %lld\n", trocas);
										printf("Tempo de execucao: %.6f segundos\n", tempo_decorrido);
										free(vetor);
								} else {
										printf("Escolha o tamanho do vetor: ");
										scanf("%lld", &tamanho);
										int *vetor;
										if (metodo == 0) {
												vetor = geraAleatorios(tamanho, semente++);
										} else {
												int ordem;
												do {
														printf("\nEscolha a ordem:\n0 - Crescente\n1 - Decrescente: ");
														scanf("%d", &ordem);
														if (ordem != 0 && ordem != 1) {
																printf("Opcao Invalida.\n");
														}
												} while (ordem != 0 && ordem != 1);
												vetor = geraOrdenados(tamanho, ordem);
										}
										long long int comparacoes = 0, trocas = 0;
										clock_t inicio = clock();
										algoritmos[opcao](vetor, tamanho, &comparacoes, &trocas);
										clock_t fim = clock();
										double tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
										printf("\nAlgoritmo: %s\n", nomes_algoritmos[opcao]);
										printf("Metodo de geracao: %s\n", nomes_metodos[metodo]);
										printf("Tamanho do vetor: %lld\n", tamanho);
										printf("Comparacoes: %lld\n", comparacoes);
										printf("Trocas: %lld\n", trocas);
										printf("Tempo de execucao: %.10f segundos\n", tempo_decorrido);
										free(vetor);
								}
						} else {
								printf("Opcao invalida.\n");
						}
				} else if (opcao != -1) {
						printf("Opcao invalida.\n");
				}

				// Solicita Enter para limpar o console
				printf("\nPressione Enter para continuar...");
				getchar();
				getchar();
				// Limpa o console
				limparConsole();

		} while (opcao != -1);

		return 0;
}
