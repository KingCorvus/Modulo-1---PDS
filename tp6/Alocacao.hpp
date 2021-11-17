#ifndef ALOCACAO_H
#define ALOCACAO_H
#include <iostream>


struct Alocacao{
    std::string dia; std::string horario; std::string sala;
    
    Alocacao();
    Alocacao(std::string dia, std::string horario, std::string sala);
    void imprimir_dados();
};
#endif