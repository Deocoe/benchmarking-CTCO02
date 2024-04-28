#ifndef GERA_VETOR_H
#define GERA_VETOR_H

// Função para gerar vetores com os dados aleatórios
int* geraAleatorios(int tam, int semente);

// Função para gerar vetores com os dados quase ordenados
int* geraQuaseOrdenados(int tam, int porcentagem);

// Função para gerar vetores com os dados ordenados em ordem crescente ou decrescente
int* geraOrdenados(int tam, int ordem);

#endif
