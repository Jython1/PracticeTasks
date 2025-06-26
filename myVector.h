#pragma once
#include <cstddef>
using std::size_t;
template<class T>
class myVector
{
private:

    /*
    It is a pointer to the underlying array that holds the elements of the vector. 
    Dynamic memory allocation is used to manage the storage.
    */
    T* m_data;
    //--------------------------------------------------------------

    /*
    This member variable keeps track of the current size of the vector, 
    i.e., the number of elements it contains.
    */
    size_t m_size;
    //--------------------------------------------------------------

    /* 
    The capacity indicates the maximum number of elements 
    that can be stored in the vector without requiring reallocation of memory.
    */
    size_t m_capacity;
    //--------------------------------------------------------------
    
public:
    /*
    Default Constructor: the vector with size 0 and a default capacity of 2, 
    allocating memory for the underlying array
    */ 
    myVector();
    //--------------------------------------------------------------
    
    /*
    Constructor with Size Argument: Allows initialization of the vector with
    a specified size, allocating memory based on the given size.
    */
    myVector(unsigned int size); // Unsigned integer values can only store positive values.
    //--------------------------------------------------------------

    /*
    Constructor with Size and Initial Value:
    Initializes the vector with the specified number of elements, 
    each initialized to the given initial value. Allocates memory based on the specified size.
    */
    myVector(unsigned int size, const T& initial); // Unsigned integer values can only store positive values.
    //--------------------------------------------------------------

    ~myVector();

    /*
    Adds an element to the end of the vector. If the current size exceeds 
    the capacity, the reserve method is called to increase the capacity and reallocate memory.
    */
    void PushBack(const T& value);
    //--------------------------------------------------------------

    /*
    This method is used to increase the capacity of the vector to a specified amount. 
    It reallocates memory and copies existing elements to the new array
    */
    void Reserve(unsigned int newCapacity); // Unsigned integer values can only store positive values.
    //--------------------------------------------------------------

    /*
    Showing all vector values
    */
    void Print();
    //--------------------------------------------------------------

    /*
    operator[] overloading: Allows accessing elements in the vector using array notation. 
    Both non-const and const versions are provided for read-only access.
    */
    T& operator[](unsigned int index);
    //--------------------------------------------------------------


    /*
    myVector<T>&
        This is the return type of the function.
        It returns a reference to the current object, allowing assignment chaining like a = b = c.

    myVector<T>::operator=
        This defines the assignment operator (=) for the class myVector<T>.
        It tells the compiler how to assign one myVector to another.

    const myVector<T>& v
        This is the parameter.
        It's a constant reference to another myVector<T> object that we want to copy from.
        Using const prevents accidental modification, and using a reference avoids unnecessary copying.

    In short:
    “Defines how to copy-assign one myVector<T> to another, returning a reference to the assigned object.”
    */
    myVector<T>& operator=(const myVector<T>& other);
    //--------------------------------------------------------------

    myVector(std::initializer_list<T> list);
};

