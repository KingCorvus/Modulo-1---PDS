#ifndef NAVE_H
#define NAVE_H
#include "Ponto2D.hpp"
#include <iostream>
#include <cmath>
struct Nave{
    Ponto2D posicao; double forca;   double energia;

    Nave();
    Nave(Ponto2D posicao, double forca);
    void mover(double dx, double dy);
    double calcular_distancia(Nave* naves);
    Nave* determinar_nave_mais_proxima(Nave** naves, int n);
    void atacar(Nave** naves, int n);
    void imprimir_status();

    
};

#endif