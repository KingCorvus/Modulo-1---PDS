#ifndef LISTA_ENCADEADA_ORDENADA_H
#define LISTA_ENCADEADA_ORDENADA_H
#include "Processo.hpp"
struct lista_encadeada_ordenada{
    int numProcessos = 0;
    Processo* head = nullptr;
    Processo* tail = nullptr;

    void adicionar_processo(Processo* proc);
    void ordena_lista(Processo* head);
};


#endif