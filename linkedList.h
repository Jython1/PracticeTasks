#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>


template<typename Type>
class LinkedList
{

public:

    class Node
    {
    public:        
    Type data;
    Node *next;

        Node(Type data = Type(), Node *next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
    };
    int size;
    Node *head;
public:
    LinkedList();
    ~LinkedList();
    void insertAtHead(Type data);
    void print();
    Type& operator[](const int index);
    int GetSize();
};

#endif