#include <iostream>
#include "Nave.hpp"

Nave::Nave(Ponto2D posicao, double forca){
    this->posicao = posicao;
    if (forca == 0){ //valor não informado é igual a zero? é possivel informar o valor zero?
        this->forca = 1.0; 
    }else{
        this-> forca = forca;
    }
    this->energia = 100;
}

void Nave::mover(double dx, double dy){
    posicao.x += dx;
    posicao.y += dy;
}

double Nave::calcular_distancia(Nave* nave){
    double dx = (nave->posicao.x - this->posicao.x);
    double dy = (nave->posicao.y - this->posicao.y);
    return sqrt(dx*dx + dy*dy);
}

Nave *Nave::determinar_nave_mais_proxima(Nave** naves, int n){ 
    double aux_1 = 0; int count = 0;
    
    for (int i = 0; i < n; i++){
       
        
        if (aux_1 == 0){ //as naves podem chegar em 0? se puder vai dar erro.
            aux_1 = calcular_distancia(naves[i]);
            count = i;
        }else{
            if (calcular_distancia(naves[i]) != 0 && aux_1 > calcular_distancia(naves[i])){
                aux_1 = calcular_distancia(naves[i]);
                count = i;
            }
        }    
    }
    return naves[count];
}

void Nave::atacar(Nave** naves, int n){
    double dano = 0;
    Nave* pontAtq = determinar_nave_mais_proxima(naves, n);
    dano = ((100/this->calcular_distancia(pontAtq))*this->forca);
    if (dano > 30){
        dano = 30;
    }else{
        dano = dano;
    }
    pontAtq->energia -= dano;
    if (pontAtq->energia <= 50){
        std::cout << "Energia Baixa!" << std::endl;
    }
}

void Nave::imprimir_status(){
    std::cout << this->posicao.x << " " <<  this->posicao.y << " " <<  this->energia << std::endl;
}