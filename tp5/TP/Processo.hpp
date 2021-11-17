#ifndef PROCESSO_H  
#define PROCESSO_H

#include <string>

struct Processo{
    int id; int prioridade; std::string nome;
    Processo* next = nullptr;
    Processo* back = nullptr;

    Processo();
    Processo(int id, std::string nome, int prioridade);
    void imprimir_dados();
};
#endif