#include <iostream>
#include "TwoSum.h"

int main()
{
    TwoSum::Solution sol;
    std::vector<int> arr = {3,3,4};
    std::vector<int> result = sol.twoSum_um(arr, 6);

    for (int index : result) {
    std::cout << index << " ";
    }
}