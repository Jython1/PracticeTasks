#include <iostream>
#include "linkedList.cpp"
using std::cout;
using std::endl;



int main()
{
    linkedList<int> numbers;
    for(int i = 0; i < 10; i++)
    {
        numbers.PushBack(i);
    }

    //numbers.PopBack();
    //numbers.PopFront();
    numbers.InsertAt(1,55);
    
    numbers.Display();
    return 0;
}