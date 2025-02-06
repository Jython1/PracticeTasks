#include <iostream>
#include "linkedList.cpp"

int main()
{

    LinkedList<int> lst1;
    lst1.insertAtHead(1);
    lst1.insertAtHead(2);
    lst1.insertAtHead(3);
    lst1.insertAtHead(4);
    //std::cout << lst1.GetSize() << std::endl;

    for(int i=0; i<lst1.GetSize(); i++)
    {
        std::cout << lst1[i] << std::endl;
    }

    return 0;
}