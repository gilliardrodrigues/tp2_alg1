#ifndef CONJUNTODISJUNTO_H
#define CONJUNTODISJUNTO_H

class ConjuntoDisjunto
{
public:
    ConjuntoDisjunto(int n);         // Construtor;
    int buscaConjunto(int u);        // Encontra o representante do conjunto que contém o vértice u;
    void uneConjuntos(int u, int v); // Une dois subconjuntos em um único conjunto;
    ~ConjuntoDisjunto();             // Destrutor;
private:
    int *representante, *rank; // Ponteiros para arrays que conterão os conjuntos e ranks de cada elemento;
    int n;                     //Nº de conjuntos;
};

#endif //CONJUNTODISJUNTO_H