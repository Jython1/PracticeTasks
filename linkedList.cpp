#include "linkedList.h"


template<typename Type>
LinkedList<Type>::LinkedList()
{
    size = 0;
    head = nullptr;
}

template<typename Type>
void LinkedList<Type>::insertAtHead(Type data)
{
    if(!head)
    {
        head = new Node(data);
        return;
    }
    Node *current = this->head;
    while(current->next)
    {
        current = current->next;
    }
    current->next = new Node(data);
    size++;
}

template<typename Type>
int LinkedList<Type>::GetSize()
{
    return size;
}



template<typename Type>
void LinkedList<Type>::print()
{
    if(!head)
    {
        std::cout << "[]" << std::endl;
        return;
    }
    Node *temp = this->head;
    std::cout << "[ ";
    while(temp)
    {
        std::cout << temp->data << ", "; 
        temp = temp->next;
    }
    std::cout << " ]" << std::endl;

}


template<typename Type>
Type & LinkedList<Type>::operator[](const int index)
{
    int counter = 0;
    Node *current = this->head;
    
    while(current != nullptr)
    {
        if(counter == index)
        {
            return current->data;
        }
        current = current->next;
        counter++;
    }
}

template<typename Type>
LinkedList<Type>::~LinkedList()
{
}
