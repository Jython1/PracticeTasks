
#include "myVector.h"



template<class T>
myVector<T>::myVector()
{
    m_size = 0;
    m_capacity = 2;
    m_data = new T[m_capacity];
}

template<class T>
myVector<T>::myVector(unsigned int size)
{
    m_size = size;
    m_capacity = size * 2;
    m_data = new T[m_capacity];
}

template<class T>
myVector<T>::myVector(unsigned int size, const T& initial)
{
    m_size = size;
    m_capacity = size * 2;
    m_data = new T[m_capacity];
    for (unsigned int i = 0; i < m_size; i++)
        m_data[i] = initial;
}



template<class T>
void myVector<T>::PushBack(const T& val)
{
    if(m_size >= m_capacity) 
        Reserve(m_capacity * 2);
    
    m_data[m_size++] = val;
}

template<class T>
void myVector<T>::Reserve(unsigned int newCapacity)
{
    T* newData = new T[newCapacity];
    for(int i = 0; i < m_size; i++)
        newData[i] = m_data[i];

    delete[] m_data;
    m_data = newData;
    m_capacity = newCapacity;
}

 
template<class T>
void myVector<T>::Print()
{
    std::cout << "[ ";
    for (int i = 0; i < m_size; ++i)
    {
        std::cout << m_data[i];
        if (i < m_size - 1)
            std::cout << ", ";
    }
    std::cout << " ]\n";
}

template<class T>
T& myVector<T>::operator[](unsigned int idx)
{
    return m_data[idx];
}

template<class T>
myVector<T>::~myVector()
{
    delete[] m_data;
}


template<class T>
myVector<T>& myVector<T>::operator=(const myVector<T>& v)
{
    if(this == &v)
        return this; //Self-assignment check: if the object is being assigned to itself, do nothing

    delete[] m_data; //Deallocate the current memory to avoid memory leaks


    /*
    Copy size and capacity from the other vector
    */
    m_size = v.m_size;
    m_capacity = v.m_capacity;
    //--------------------------------------------------------------

    m_data = new T[m_capacity]; //Allocate new memory based on the copied capacity


    /*
    Copy each element from the other vector to this one
    */
    for(size_t i = 0; i < m_size; i++)
        m_data[i] = v.m_data[i];
    //--------------------------------------------------------------

    return this; //Return reference to the current object to allow chained assignments
}

template<class T>
myVector<T>::myVector(std::initializer_list<T> list)
{
    m_size = list.size();
    m_capacity = m_size * 2;
    m_data = new T[m_capacity];

    size_t index = 0;
    for (const T& val : list)
        m_data[index++] = val;
}
