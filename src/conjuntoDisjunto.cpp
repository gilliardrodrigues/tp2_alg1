#include <iostream>
#include "conjuntoDisjunto.h"

ConjuntoDisjunto::ConjuntoDisjunto(int n)
{
    this->n = n;
    // Alocando memória dinamicamente parac criar n subconjuntos:
    representante = new int[n];
    rank = new int[n];
    //Inicialmente, todos os vértices estão em conjuntos diferentes e possuem rank 0:
    for (int i = 0; i < n; i++)
    {
        representante[i] = i; // Cada elemento é representante de si mesmo;
        rank[i] = 0;
    }
}

int ConjuntoDisjunto::buscaConjunto(int u) // Encontra o representante do conjunto que contém o vértice u;
{
    // Implementação com otimização de compressão de caminho;
    if (u != representante[u])
        representante[u] = buscaConjunto(representante[u]);
    return representante[u];
}

void ConjuntoDisjunto::uneConjuntos(int u, int v) // Une dois subconjuntos em um único conjunto;
{
    // Implementação com otimização através de união por rank;
    // Faz a árvore com a menor altura uma subárvore da outra árvore:
    if (rank[u] > rank[v])
        representante[v] = u;
    else // Se o rank[u] <= rank[v]
        representante[u] = v;
    if (rank[u] == rank[v])
        rank[v]++;
}

ConjuntoDisjunto::~ConjuntoDisjunto()
{
    delete representante;
    delete rank;
}