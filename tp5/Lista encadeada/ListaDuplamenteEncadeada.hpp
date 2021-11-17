#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

struct Node{
    int data;
    Node* next;
    Node* prev;
};

struct ListaEncadeada{
    Node* head = nullptr;
    Node* tail = nullptr;
    int numElementos = 0;

    void insertNode(int data);
    void removeNode(int data);
    void display();
    void numElementos();
};

#endif;