#ifndef LISTENC_H  
#define LISTENC_H

struct Node{
    int data;
    Node* next;
};
struct List{
    Node* head = nullptr;
    Node* tail = nullptr;

    void insertNode(int data);
    void removeNode(int data);
    void display();
};

#endif;