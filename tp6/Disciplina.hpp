#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#include <iostream>
#include <map>
#include <vector>
#include "Alocacao.hpp"
#include <algorithm>

typedef std::pair<std::string, Alocacao*> pair;

struct Disciplina
{
    std::string codigo; std::string nome;
    std::map<std::string, Alocacao*> alocacao;

    Disciplina(std::string codigo, std::string nome);
    Disciplina();
    void inserir_alocacao(std::string dia, std::string horario, std::string sala);
    void remover_alocacao(std::string horario);
    void imprimir_alocacao();
    
    //void ordenarMap_alocacao();
};

#endif