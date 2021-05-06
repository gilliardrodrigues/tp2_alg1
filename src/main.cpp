#include <iostream>
#include "grafo.h"

using namespace std;

int main()
{
    int qtd_pontos_turisticos, qtd_trechos_possiveis;

    cin >> qtd_pontos_turisticos >> qtd_trechos_possiveis;

    Grafo belleville(qtd_pontos_turisticos); // Instancia um objeto do tipo Grafo, passando como parâmetro o nº de vértices;

    belleville.insereValoresTuristicos();              // Popula o vetor "valores_turisticos" com a entrada do usuário;
    belleville.inserePropostas(qtd_trechos_possiveis); // Recebe as propostas de trechos e custos e insere no grafo;
    belleville.kruskal();                              // Roda o algoritmo de Kruskal para gerar a AGM;
    belleville.imprimeResultado();                     // Imprime o resultado na tela;
    return 0;
}
