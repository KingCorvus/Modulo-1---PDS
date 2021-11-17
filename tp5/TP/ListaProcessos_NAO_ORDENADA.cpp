#include <iostream>
#include "ListaProcessos.hpp"

void ListaProcessos::adicionar_processo(Processo* proc){
    Processo* aux = new Processo;
    aux = proc;

    if(head == nullptr){
        head = aux;
        tail = aux;
    }else{
        tail->next = aux;
        tail = aux;
    } ordena_lista(head);
    delete aux;
}

Processo* ListaProcessos::remover_processo_maior_prioridade(){
    Processo *current = head; Processo *previous = nullptr;

    Processo *auxPrc = new Processo;
    while (current != nullptr){
        if (current == head){
            auxPrc = current;
        }else{
            if (current->prioridade > auxPrc->prioridade){
                auxPrc = current;
            }
        }previous = current; current = current->next;  
    }current = head; previous = nullptr;
    
    while (current != auxPrc){
        previous = current;
        current = current->next;
    }delete auxPrc;

    if (current == head){
        head = current->next;
    }else{
        if (current->next == nullptr){
            previous->next = nullptr;
            tail = previous;
        }else{
            previous->next = current->next;
        }
    }delete current;
    return;
}

Processo* ListaProcessos::remover_processo_menor_prioridade(){
    Processo *current = head; Processo *previous = nullptr;

    Processo *auxPrc = new Processo;
    while (current != nullptr){
        if (current == head){
            auxPrc = current;
        }else{
            if (current->prioridade < auxPrc->prioridade){
                auxPrc = current;
            }
        }previous = current; current = current->next;  
    }current = head; previous = nullptr;
    
    while (current != auxPrc){
        previous = current;
        current = current->next;
    }delete auxPrc;

    if (current == head){
        head = current->next;
    }else{
        if (current->next == nullptr){
            previous->next = nullptr;
            tail = previous;
        }else{
            previous->next = current->next;
        }
    }delete current;
    return;
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
    return;
}

void ListaProcessos::imprimir_lista(){
    Processo *auxPrc = head;
    while (auxPrc != tail){
        auxPrc->imprimir_dados();
        auxPrc = auxPrc->next;
    }
}


/********************************************************************/
void ListaProcessos::adicionar_processo(Processo* proc){
    Processo* aux = new Processo; aux = nullptr;

    if(head == nullptr){
        head = proc;
        head->next = tail;
    }else{
        if (tail == nullptr){
            tail = proc;
            tail->back = head;
        }else{
            aux = tail; aux->next = tail; aux->back = tail->back;
            tail = proc; tail->back = aux;
        }
        
    }count++; 
    ordena_lista(head);
    
    delete aux;
    return;
}




//Início do ordenador por método Quick Sort
void ListaProcessos::quickSort(Processo* head, Processo* tail){
    Processo* aux = new Processo; aux = head;
    if(head != tail){
        Processo* j = separa(head, tail);
        quickSort(head,j->back);
        quickSort(j->next,tail);
    }
}

void ListaProcessos::troca(Processo* menProc, Processo* maiProc){
    Processo aux = *menProc;
    *menProc = *maiProc;
    *maiProc = aux;
}

Processo* ListaProcessos::separa(Processo* head, Processo* tail){
    int pivot = tail->prioridade;
    Processo* i;
    if(head->back != nullptr){
        i = head->back;
    }else{
        i = head;
    }
 
    while (head != tail->back){
        if(head->prioridade < pivot){
            troca(i, tail);
        }
        troca(i->next, head);
        head = head->next;
    }
    return i->next;
}
//Fim do ordenador