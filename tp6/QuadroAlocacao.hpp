#ifndef QUADROALOCACAO_H
#define QUADROALOCACAO_H
#include <iostream>
#include "Alocacao.hpp"
#include "Disciplina.hpp"

struct QuadroAlocacao
{
    std::map<std::string, Disciplina*> quadroAlocacao;

    void inserir_alocacao(std::string codigo, std::string nome, std::string dia,std:: string horario, std::string sala);
    void remover_alocacao_disciplina(std::string codigo, std::string horario);
    void recuperar_disciplinas_mais_ofertadas();
    void imprimir_alocacao_completa();
};



#endif