

class NumbGuesser
{
int minNumber, maxNumber;
int attemptsCounter = 0;
public:
    int* makeArray(int firstNumb, int secondNumb);
    void guessNumber(int arr[], int arraySize);
};