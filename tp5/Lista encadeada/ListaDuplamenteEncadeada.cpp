#include "ListaDuplamenteEncadeada.hpp"
#include <iostream>

void ListaEncadeada::insertNode(int data){
    Node* aux = new Node;
    aux->data = data;
    aux->next = nullptr;

    if(head == nullptr){
        head = aux;
        tail = aux;
    }else{
        tail->next = aux;
        tail = aux;
    }
}