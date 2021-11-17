#include <iostream>
#include "Ponto2D.hpp"

Ponto2D::Ponto2D(){
}
Ponto2D::Ponto2D(double x, double y){
    this->x = x;
    this->y = y;
}

double Ponto2D::calcular_distancia(Ponto2D* ponto){
    double dx = (ponto->x - this->x);
    double dy = (ponto->y - this->y);
    return sqrt(dx*dx + dy*dy);
}