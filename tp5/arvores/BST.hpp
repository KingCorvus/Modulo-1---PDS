#ifndef BST_H
#define BST_H
#include <iostream>

struct NodeT{
    int data;
    NodeT* esq;
    NodeT* dir;
};

struct BST{
    NodeT* root = nullptr;

    void insertNodeHelper(NodeT* root, int data);

    void insertNode(int data);
    void removeNode(int data);
    
    void display();
    /*1*/void inorder(NodeT* aux);
};


#endif