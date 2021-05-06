#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include "conjuntoDisjunto.h"
#include "aresta.h"
#include "grafo.h"

using namespace std;

Grafo::Grafo(int V)
{
    this->V = V;
    valores_turisticos = new int[V]; // Aloca memória para armazenar os valores turísticos;
}

void Grafo::insereValoresTuristicos() // Popula o vetor "valores_turisticos" com a entrada do usuário;
{
    for (int i = 0; i < V; i++)
        cin >> valores_turisticos[i];
}

void Grafo::adicionaArestaPonderada(int u, int v, int custo, int atratividade) // Insere uma aresta ponderada no grafo;
{
    Aresta trecho(u, v, custo, atratividade); // Cria uma aresta com os argumentos passados como parâmetro na função;
    G.push_back(trecho);                      // Insere a aresta no grafo;
}

void Grafo::inserePropostas(int E) // Recebe as propostas de trechos e custos e insere no grafo;
{
    int ponto_u, ponto_v, custo_trecho, atratividade_trecho;
    for (int i = 0; i < E; i++)
    {
        cin >> ponto_u >> ponto_v >> custo_trecho;
        atratividade_trecho = valores_turisticos[ponto_u] + valores_turisticos[ponto_v]; //Calcula a atratividade do trecho;
        adicionaArestaPonderada(ponto_u, ponto_v, custo_trecho, atratividade_trecho);
    }
}

void Grafo::kruskal() // Roda o algoritmo de Kruskal para gerar a AGM;
{
    int num_arestas_G = G.size();
    sort(G.begin(), G.end());              //Ordena as arestas pelo menor custo e caso haja custo igual, dá prioridade àquela com maior atratividade;
    ConjuntoDisjunto conjunto_disjunto(V); // Instancia um objeto do tipo ConjuntoDisjunto;
    for (int i = 0; i < num_arestas_G; i++)
    {
        int u = conjunto_disjunto.buscaConjunto(G[i].obter_u());
        int v = conjunto_disjunto.buscaConjunto(G[i].obter_v());
        if (u != v) // Se forem diferentes, então não forma ciclo e a aresta é inserida na AGM;
        {
            AGM.push_back(G[i]);
            conjunto_disjunto.uneConjuntos(u, v); // Faz a união;
        }
    }
}

void Grafo::imprimeResultado()
{
    int qtd_arestas_AGM = AGM.size();
    int custo_total_minimo = 0;
    int atratividade_agregada = 0;
    int qtd_trechos_por_ponto_turistico[V]; // Armazena a quantidade de trechos chegando/saindo de cada ponto de interesse.

    for (int i = 0; i < qtd_arestas_AGM; i++)
        custo_total_minimo += AGM[i].obter_custo(); // Calcula o custo total da AGM;

    for (int i = 0; i < qtd_arestas_AGM; i++)
        atratividade_agregada += AGM[i].obter_atratividade(); // Calcula a atratividade agregada da AGM;

    memset(qtd_trechos_por_ponto_turistico, 0, sizeof(int) * V); // Seta todas as posições do vetor como 0;

    int id_u, id_v;
    for (int i = 0; i < qtd_arestas_AGM; i++) // Conta quantas arestas há chegando/saindo de cada ponto de interesse;
    {
        id_u = AGM[i].obter_u();
        id_v = AGM[i].obter_v();
        qtd_trechos_por_ponto_turistico[id_u]++;
        qtd_trechos_por_ponto_turistico[id_v]++;
    }
    // Imprime as saídas do TP:
    cout << custo_total_minimo << " " << atratividade_agregada << endl;
    for (int i = 0; i < V; i++)
        cout << qtd_trechos_por_ponto_turistico[i] << " ";
    cout << endl;
    for (int i = 0; i < qtd_arestas_AGM; i++)
        cout << AGM[i].obter_u() << " " << AGM[i].obter_v() << " " << AGM[i].obter_custo() << endl;
}

Grafo::~Grafo()
{
    G.clear();
    AGM.clear();
    delete valores_turisticos;
}