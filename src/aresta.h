#ifndef ARESTA_H
#define ARESTA_H

class Aresta
{
public:
    Aresta(int u, int v, int custo, int atratividade); // Construtor;
    //Getters:
    int obter_u();
    int obter_v();
    int obter_custo();
    int obter_atratividade();
    bool operator<(const Aresta &trecho2) const; // Sobrescrita do operador "<";
private:
    int u, v, custo, atratividade;
};

#endif //ARESTA_H