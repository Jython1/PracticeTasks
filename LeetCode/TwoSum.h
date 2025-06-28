/**
 * TwoSum.h - Header file for Two Sum problem solutions
 * 
 * This header defines the interface for solving the classic Two Sum problem:
 * Given an array of integers and a target sum, find two numbers in the array
 * that add up to the target and return their indices.
 * 
 * The class provides two different algorithmic approaches:
 * 1. Two Pointers approach (requires sorted array)
 * 2. Hash Map approach (works with unsorted arrays)
 */

#ifndef TWOSUM_H
#define TWOSUM_H

#include <vector>

/**
 * TwoSum namespace - encapsulates all Two Sum related functionality
 * Prevents naming conflicts and provides logical grouping
 */
namespace TwoSum
{
    /**
     * Solution class - contains different implementations of the Two Sum algorithm
     * 
     * This class provides multiple approaches to solve the Two Sum problem,
     * each with different time/space complexity trade-offs.
     */
    class Solution {
        public:
            /**
             * Two Sum using Two Pointers approach
             * 
             * @param nums - reference to vector of integers (should be sorted for optimal performance)
             * @param target - the target sum we're looking for
             * @return vector<int> - indices of the two numbers that sum to target, empty if none found
             * 
             * Time Complexity: O(1) if sorted, O(n log n) if sorting needed
             * Space Complexity: O(1)
             * 
             * Best used when: array is already sorted or when minimizing space usage is critical
             */
            std::vector<int> twoSum_twoptrs(std::vector<int>& nums, int target);

            /**
             * Two Sum using Hash Map (Unordered Map) approach
             * 
             * @param nums - reference to vector of integers (can be unsorted)
             * @param target - the target sum we're looking for
             * @return vector<int> - indices of the two numbers that sum to target, empty if none found
             * 
             * Time Complexity: O(n)
             * Space Complexity: O(n)
             * 
             * Best used when: array is unsorted or when minimizing time complexity is critical
             */
            std::vector<int> twoSum_um(std::vector<int>& nums, int target);

        private:
            /**
             * Input validation helper function
             * 
             * @param nums - const reference to vector of integers to validate
             * @param target - target value to validate
             * @return bool - true if input is out of bounds/invalid, false if valid
             * 
             * Checks:
             * - Array size (must be >= 2 and <= 10^4)
             * - Target value bounds (must be within [-10^9, 10^9])
             * - Individual element bounds (must be within [-10^9, 10^9])
             * 
             * This function ensures the input meets typical problem constraints
             * and prevents undefined behavior or performance issues.
             */
            bool IsOutOfBounds(const std::vector<int>& nums, int target);
    };
}

#endif // TWOSUM_H