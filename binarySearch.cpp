#include <iostream>
#include <cmath>
#include "binarySearch.h"
using namespace std;


int* NumbGuesser::makeArray(int firstValue, int lastValue)
{

    int arrSize = lastValue-firstValue+1;
    int *arrayValues = new int[arrSize];
    for(int i = firstValue; i <= lastValue; i++)
    {
        arrayValues[i] = firstValue + i;
    }
    return arrayValues;
}

void NumbGuesser::guessNumber(int arr[], int arraySize)
{
    attemptsCounter ++;
    int middleArrIndex = (arraySize/2)-1;
    string answer;
    cout << "Your number is " << arr[middleArrIndex] << ". Right?" << endl;
    cout << "Type 'less', 'more' or 'yes': ";
    cin >> answer;
    

    if (answer == "less")
    {
        
        int newArrSize = middleArrIndex + 1;
        if(newArrSize < 3) 
        {
            cout << "Finally, You number is " << arr[0] << endl;
            cout << "I used only " << attemptsCounter << " attempt(s) to guess.";
            return;
        }
        
        int *newArr = new int[middleArrIndex];
        for(int i = 0; i < newArrSize; i++)
        {
            newArr[i] = arr[i];
        }
        guessNumber(newArr, newArrSize);

    }

    else if(answer == "more")
    {
        int newArrSize = middleArrIndex + 1;
                if(newArrSize < 3) 
        {
            cout << "Finally, You number is " << arr[0] << endl;
            cout << "I used only " << attemptsCounter << " attempt(s) to guess.";
            return;
        }
        
        int *newArr = new int[middleArrIndex];
        
        for(int i = 0; i < newArrSize; i++)
        {
            newArr[i] = arr[middleArrIndex + i + 1];
        }
        guessNumber(newArr, newArrSize);
    }

    if (answer == "yes") cout << "I used only " << attemptsCounter << " attempt(s) to guess.";
    if (answer == "exit") return;


}

