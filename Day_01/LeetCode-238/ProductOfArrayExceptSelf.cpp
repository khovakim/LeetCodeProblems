// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
 

// Constraints:

// 2 <= nums.length <= 105
// -30 <= nums[i] <= 30
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(const std::vector<int>& nums) {
        int multiplyOfNums = 1;
        bool therIsZeroInArr = false;
        std::size_t countOfZero = 0;

        for (std::size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                therIsZeroInArr = true;
                ++countOfZero;
                continue ;
            }
            multiplyOfNums *= nums[i];
        }
        if (countOfZero > 1) {
            multiplyOfNums = 0;
        }
        std::vector<int> ret(nums.size());
        for (std::size_t i = 0; i < nums.size(); ++i) {
            if (therIsZeroInArr == true) {
                if (nums[i] == 0) {
                    ret[i] = multiplyOfNums;
                } else {
                    ret[i] = 0;
                }
            } else {
                ret[i] = multiplyOfNums / nums[i];
            }
        }
        return ret;
    }
};