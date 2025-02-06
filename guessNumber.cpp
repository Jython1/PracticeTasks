#include <iostream>
#include "guessNumber.h"
using namespace std;





int* NumbGuesser::makeArray(int firstValue, int lastValue)
{


    int *arrayValues = new int[lastValue]{};
    for(int i = 0; i <= lastValue; i++)
    {
        arrayValues[i] = firstValue;
        firstValue++;
    }
    return arrayValues;
}

void NumbGuesser::guessNumber(int arr[], int arraySize)
{
    attemptsCounter ++;
    int middleArrIndex = arraySize/2;
    if(arraySize < 2) 
    {
        cout << "Finally, You number is " << arr[middleArrIndex] << endl;
        cout << "I used only " << attemptsCounter << " attempt(s) to guess." << endl;
        return;
    }
    string answer;
    cout << "Your number is " << arr[middleArrIndex] << ". Right?" << endl;
    cout << "Type 'less', 'more' or 'yes': ";
    cin >> answer;
    

    if (answer == "less")
    {       
        int newArr[middleArrIndex];
        for(int i = 0; i < middleArrIndex; i++)
        {
            newArr[i] = arr[i];
        }
        guessNumber(newArr, middleArrIndex);

    }

    else if(answer == "more")
    {
        int newArrSize = middleArrIndex;

        int newArr[middleArrIndex];
        
        for(int i = 0; i < middleArrIndex; i++)
        {
            newArr[i] = arr[middleArrIndex + i + 1];
        }
        guessNumber(newArr, newArrSize);
    }

    if (answer == "yes") cout << "I used only " << attemptsCounter << " attempt(s) to guess." << endl;
    if (answer == "exit") return;


}

