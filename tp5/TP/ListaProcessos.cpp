#include <iostream>
#include "ListaProcessos.hpp"
#include "Processo.hpp"

void ListaProcessos::adicionar_processo(Processo* proc){
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


void ListaProcessos::ordena_lista(Processo* head){
    std::sort();
    /*for (int i = 0; i < numProcessos; i++){
        
        while (head->next != tail){
            Processo* comparador = new Processo; comparador = (head->next);
            Processo aux;

            if (head->prioridade < comparador->prioridade){
                
                aux = *head; aux.next = comparador->next; aux.back = comparador->back;
                *head = *comparador;
                *head->next = aux;
                ordena_lista(head);
            } else{
                ordena_lista(head->next);
            }
        }
    }*/
}

Processo* ListaProcessos::remover_processo_maior_prioridade(){
    Processo* aux = new Processo;
    aux = head;
    head = head->next;
    
    delete aux;
    numProcessos--;
    
    return 0;
}

Processo* ListaProcessos::remover_processo_menor_prioridade(){
    Processo* aux = new Processo;
    aux = tail;
    tail = tail->back;

    delete aux;
    numProcessos--;
    
    return 0;
}

Processo* ListaProcessos::remover_processo_por_id(int id){
    Processo* current = new Processo; current = head; 
    Processo* previous = new Processo; previous = nullptr;

    while (current->id != id){
        previous = current;
        current = current->next;
    }

    if (current == head){
        head = head->next;
        delete previous;
    }else{
        if (current->next == nullptr){
            tail = tail->back;
            delete previous;
        }else{
            previous->next = current->next;
        }
    }delete current;
    numProcessos--;

    return 0;
}

void ListaProcessos::imprimir_lista(){
    Processo* aux = new Processo; aux = head;
    
    while (aux != nullptr){
        aux->imprimir_dados();
        aux = aux->next;
    } 
    delete aux;
}