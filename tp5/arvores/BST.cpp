#include <iostream>
#include "BST.hpp"

NodeT* createNode(int data){
    NodeT* aux = new NodeT;
    aux->data = data;
    aux->dir = nullptr;
    aux->esq = nullptr;

    return aux;
}

void BST::insertNode(int data){
    if (root != nullptr){
        insertNodeHelper(root,data);
    }else{
        root = createNode(data);
    }
}

void BST::insertNodeHelper(NodeT* aux, int data){
    if (data <= aux->data){
        if (aux->esq == nullptr){
            aux->esq = createNode(data);
            return;
        }else{
            insertNodeHelper(aux->esq, data);
        }
    }else{
        if (aux->dir == nullptr){
            aux->dir = createNode(data);
            return;
        }else{
            insertNodeHelper(aux->dir, data);
        }
    }
}

void BST::display(){
   inorder(root); 
   std::cout << std::endl;
}

void BST::inorder(NodeT* root){
    if (root == nullptr){
        return;
    }
    inorder(root->esq);
    std::cout << root->data << " ";
    inorder(root->dir); 
}