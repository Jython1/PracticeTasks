#include<iostream>
#include <math.h>
#include <unordered_map>
#include "TwoSum.h"
using namespace TwoSum;

/**
 * Two Sum solution using Two Pointers approach
 * Time Complexity: O(1) if array is sorted, O(n log n) if sorting is needed
 * Space Complexity: O(1)
 * 
 * This approach works best when the array is already sorted.
 * It uses two pointers starting from opposite ends of the array.
 */
std::vector<int> Solution::twoSum_twoptrs(std::vector<int>& nums, int target)
{
    // Early exit if input doesn't meet constraints
    if(IsOutOfBounds(nums, target)) return{};

    // Initialize pointers at the beginning and end of array
    int leftIdx = 0;                    // Start pointer at first element
    int rightIdx = nums.size()-1;       // End pointer at last element

    // Continue until pointers meet
    while (leftIdx < rightIdx)
    {
        // Calculate sum of elements at current pointer positions
        int sum = nums[leftIdx] + nums[rightIdx];

        // If sum is too small, move left pointer right to increase sum
        if(sum < target) leftIdx++;
        // If sum is too large, move right pointer left to decrease sum
        else if(sum > target) rightIdx--;
        // If sum equals target, we found our pair - return their indices
        else return {leftIdx, rightIdx};
    }
    
    // No valid pair found
    return{};
}

/**
 * Two Sum solution using Hash Map (Unordered Map) approach
 * Time Complexity: O(n) - single pass through array
 * Space Complexity: O(n) - hash map can store up to n elements
 * 
 * This approach works with unsorted arrays and is generally more efficient.
 * It trades space for time by storing previously seen elements in a hash map.
 */
std::vector<int> Solution::twoSum_um(std::vector<int>& nums, int target) 
{
    // Early exit if input doesn't meet constraints
    if (IsOutOfBounds(nums, target)) return {};

    // Hash map to store: {value -> index} pairs of previously seen elements
    std::unordered_map<int, int> map;
    
    // Iterate through array once
    for (size_t i = 0; i < nums.size(); ++i) {
        // Calculate what number we need to reach the target
        const int complement = target - nums[i];
        
        // Check if we've seen the complement before
        if (map.find(complement) != map.end())
            // Found it! Return the stored index and current index
            return {map[complement], static_cast<int>(i)};
        
        // Store current element and its index for future lookups
        map[nums[i]] = static_cast<int>(i);
    }
    
    // No valid pair found
    return {};
}

/**
 * Input validation function to check if parameters meet problem constraints
 * This helps prevent undefined behavior and ensures the solution works
 * within the expected parameters of the Two Sum problem.
 */
bool Solution::IsOutOfBounds(const std::vector<int>& nums, int target)
{
    // Define constraint constants based on typical LeetCode Two Sum problem
    const long TARGET_BOUND = 1000000000L;  // 10^9 - max absolute value for target/elements
    const size_t LENGTH_BOUND = 10000;      // 10^4 - max array length
    
    // Check array size constraints
    // Array must have at least 2 elements to form a pair
    // Array shouldn't exceed maximum allowed length
    if (nums.size() < 2 || nums.size() > LENGTH_BOUND) 
        return true;
    
    // Check target value constraints
    // Target must be within the specified bounds
    if (target > TARGET_BOUND || target < -TARGET_BOUND) 
        return true;

    // Check individual element constraints
    // Each array element must be within the specified bounds
    for (int n : nums) {
        if (n > TARGET_BOUND || n < -TARGET_BOUND)
            return true;
    }

    // All constraints satisfied
    return false;
}