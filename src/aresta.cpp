#include <iostream>
#include "aresta.h"

Aresta::Aresta(int ponto_u, int ponto_v, int custo_trecho, int atratividade_trecho)
{
    u = ponto_u;
    v = ponto_v;
    custo = custo_trecho;
    atratividade = atratividade_trecho;
}
int Aresta::obter_u()
{
    return u;
}
int Aresta::obter_v()
{
    return v;
}
int Aresta::obter_custo()
{
    return custo;
}
int Aresta::obter_atratividade()
{
    return atratividade;
}
bool Aresta::operator<(const Aresta &trecho2) const // Sobrescrita do operador "<" para que o método "sort" ordene conforme as especificações do TP;
{                                                   
    // Retorna True se o custo do trecho 1 for menor que o do 2 ou então quando o custo é igual e a atratividade do 1 é maior;
    return (custo < trecho2.custo || (custo == trecho2.custo && atratividade > trecho2.atratividade));
}
