#ifndef LISTAPROCESSOS_H  
#define LISTAPROCESSOS_H
#include "Processo.hpp"
#include <algorithm>

struct ListaProcessos{
    int numProcessos = 0;
    Processo* head = nullptr;
    Processo* tail = nullptr;
    
    //funções padrão
    void adicionar_processo(Processo* proc);
    Processo* remover_processo_maior_prioridade();
    Processo* remover_processo_menor_prioridade();
    Processo* remover_processo_por_id(int id);
    void imprimir_lista();
    
    //funções auxiliares
    void ordena_lista(Processo* head);
    
};
#endif