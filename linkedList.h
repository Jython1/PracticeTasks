#pragma once
#include <iostream>

/*
Linked list is a dynamic data structure where elements are connected via pointers, allowing for efficient insertion and deletion operations. 
Each element is stored in a node, and the nodes are linked together to form the list.
*/



/*
This is a nested class within the linked list class. 
It defines the structure of each node in the linked list. 
Each node typically contains two fields:
*/
template<class T>
class Node
{
public:
    T data; //This field stores the actual data of the element.
    Node* next = nullptr; //This field is a reference to the next node in the sequence.
    Node(T value)
    {
        data = value;// 
        next = nullptr;
    }
};
//-------------------------------------------------------


template<class T>
class linkedList //This is the main class representing the linked list. It contains:
{
private:
    /*
    This is a reference to the first node in the list. 
    If the list is empty, `head` is `null`
    */
    Node<T>* head;
    //-------------------------------------------------------

    size_t m_size;

public:
    
    linkedList(/* args */);
    ~linkedList();

    /*
    Method adds a new element to the end of the linked list. This is where you create an instance of the `LinkedList` class and perform operations on it. In this example, we create a linked list, insert some elements into it, and then display the list.


    It first creates a new node with the given data. If the list is empty (`head` is `null`), the new node becomes the `head`. 
    Otherwise, it traverses the list until it reaches the last node, then appends the new node to the end.
    */
    void PushBack(T value);
    //-------------------------------------------------------
    
    void PushFront(T value);
    void Display() const;
    size_t Size();
    T& operator[](size_t index);
    void PopFront();
    void PopBack();

    void InsertAt(size_t index, T value);
    void RemoveAt(size_t index);
};


