#include "linkedList.h"

template<class T>
linkedList<T>::linkedList()// Constructor: initialize head to nullptr
{
    head = nullptr;
    m_size = 0;
}

template<class T>
linkedList<T>::~linkedList()
{
    Node<T>* current = head;
    while (current)
    {
        Node<T>* deleteNode = current;
        current = current->next;
        delete deleteNode;
    }
    
}

// Add a node with value to the end of the list
template<class T>
void linkedList<T>::PushBack(T value)
{
    Node<T>* newNode = new Node<T>(value);

    if(!head)
    {
        head = newNode;
    }
        
    else // Traverse to the last node
    {
        Node<T>* temp = head;
        while (temp->next)
        {
            temp = temp->next; // Move to the last node
        }
        temp->next = newNode; // Set the last node's next to new node
        
    }
    m_size++;
}

template<class T>
void linkedList<T>::PushFront(T value)
{
    Node<T>* newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
    m_size++;
}

template<class T>
void linkedList<T>::Display() const
{
    Node<T>* temp = head;
    while(temp)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "null" << std::endl;
}

template<class T>
size_t linkedList<T>::Size()
{
    return m_size;
}

template<class T>
T& linkedList<T>::operator[](size_t index)
{
    Node<T>* current = head;
    for(size_t i = 0; i < index; ++i)
    {
        current = current->next;
    }
    return current->data;
}

template<class T>
void linkedList<T>::PopFront()
{
    if(!head)
        throw std::runtime_error("ERROR: Cannot remove from empty list");

    Node<T>* temp = head;
    head = head->next;
    delete temp;
    m_size--;
}

template<class T>
void linkedList<T>::PopBack()
{
    if(!head)
        throw std::runtime_error("ERROR: Cannot remove from empty list");

    if(!head->next) //If there is only one element
    {
        delete head;
        head = nullptr;
        return;
    }

    Node<T>* current = head;
    while (current->next->next)
    {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
    m_size--;

}

template<class T>
void linkedList<T>::InsertAt(size_t index, T value)
{
    if (index > m_size)
        throw std::out_of_range("ERROR: Index out of range");

    if(index == 0)
    {
        PushFront(value);
        return;
    }

    /*
    Create a new node on the heap with the given value.
    The node's 'next' is automatically 'nullptr' in its constructor.
    */
    Node<T>* newNode = new Node<T>(value); 
    Node<T>* current = head;


    /*
    Move the current pointer to the node just before the insert location.
    Why index - 1? Because we want to insert after current, not at current.
    */
    for(size_t i = 0; i < index - 1; ++i)
        current = current->next;

    newNode->next = current->next; //The new node should point to the node that was after current.
    current->next = newNode; //Insert the new node after current.
    m_size++;
}

template<class T>
void linkedList<T>::RemoveAt(size_t index)
{
    if (index >= m_size || !head) {
        throw std::out_of_range("Index out of bounds");
    }

    if(index == 0)
    {
        PopFront();
        return;
    }
    

    else if(index == m_size)
    {
        PopBack();
        return;
    }

    Node<T>* current = head;
    for(size_t i = 0; i < index-1; ++i)
    {
        current = current->next;
    }

    Node<T>nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    delete nodeToDelete;

}

    