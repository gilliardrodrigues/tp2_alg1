#ifndef GRAFO_H
#define GRAFO_H
#include "aresta.h"
#include <vector>

using namespace std;

class Grafo
{
public:
    Grafo(int V);
    void insereValoresTuristicos();                                          // Popula o vetor "valores_turisticos" com a entrada do usuário;
    void adicionaArestaPonderada(int u, int v, int custo, int atratividade); // Insere uma aresta ponderada no grafo;
    void inserePropostas(int E);                                             // Recebe as propostas de trechos e custos e insere no grafo;
    void kruskal();                                                          // Algoritmo de Kruskal para gerar a AGM;
    void imprimeResultado();
    ~Grafo();

private:
    int V;
    vector<Aresta> G;   // Grafo;
    vector<Aresta> AGM; // Árvore geradora mínima;
    int *valores_turisticos;
};

#endif //GRAFO_H