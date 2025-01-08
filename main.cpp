#include <iostream>
#include "binarySearch.cpp"

int main()
{

    int firstValue, lastValue;
    cout << "Enter min number: ";
    cin >> firstValue;
    cout << "Enter max number: ";
    cin >> lastValue;
    

    if(firstValue > lastValue)
    {
        cout << "Wrong values of numbers. First number can't be greater than second one!";
        
    }
    else
    {
        NumbGuesser arr;
        int *firstArray = arr.makeArray(firstValue, lastValue);
        
        int arraySize = lastValue-firstValue+1;

        /*
        for(int i = 0; i < arraySize; i++)
        {
            cout << firstArray[i] << endl;
        }

        !!!program still in development and it may work incorrectly
        */
        arr.guessNumber(firstArray, arraySize);
    }

    
}