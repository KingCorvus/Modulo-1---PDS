#include <iostream>
#include "lista_encadeada_ordenada.hpp"

void lista_encadeada_ordenada::adicionar_processo(Processo* proc){
    if(head == nullptr){
        head = proc; tail = proc;
    }else{
        if(head == tail){
            tail = proc; 
            head->next = tail; tail->back = head;
        }else{
            tail->next = proc; proc->back = tail;
            tail = tail->next;
        }
    }numProcessos++;
    ordena_lista(head);
}


void lista_encadeada_ordenada::ordena_lista(Processo* head){
    Processo* comparador = new Processo; comparador = head->next;
    
    if(head->prioridade < comparador->prioridade){
        Processo* aux = new Processo; aux = head;
        aux->next = comparador->next; aux->back = comparador->back;
        head = comparador; 
        head->next = aux;
    }delete comparador;
    head = head->next;
    
    ordena_lista(head);
}