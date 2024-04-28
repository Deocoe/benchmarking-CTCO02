#ifndef ALGORITMOS_H
#define ALGORITMOS_H

//Função do InsertSort
void insertionSort(int vetor[], int n, int *comparacoes, int *trocas);

//Funcão do SelectionSort
void selectionSort(int vetor[], int n, int *comparacoes, int *trocas);

//Funcoes para o MergeSort
void merge(int vetor[], int inicio, int meio, int fim, int *comparacoes, int *trocas);
void mergeSort(int vetor[], int inicio, int fim, int *comparacoes, int *trocas);
void MergeSort(int vetor[], int n, int *comparacoes, int *trocas);

//Funcoes para o QuickSort
void troca(int* a, int* b, int* trocas);
int particao(int vetor[], int inicio, int fim, int* comparacoes, int* trocas);
void quickSort(int vetor[], int inicio, int fim, int* comparacoes, int* trocas);
void QuickSort(int vetor[], int n, int* comparacoes, int* trocas);

//Funcao para o shellsort
void shellSort(int vetor[], int n, int* comparacoes, int* trocas);

#endif
