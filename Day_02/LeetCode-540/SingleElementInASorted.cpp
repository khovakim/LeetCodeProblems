// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.

 

// Example 1:

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:

// Input: nums = [3,3,7,7,10,11,11]
// Output: 10
 

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 105

#include <vector>

class Solution {
public:
    int singleNonDuplicate(const std::vector<int>& nums) {
        if (nums.size() == 1 || nums[0] != nums[1]) {
            return nums[0];
        } else if (nums[nums.size() - 1] != nums[nums.size() - 2]) {
            return nums[nums.size() - 1];
        }

        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;

        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            } else if ((mid % 2 == 0 && nums[mid] == nums[mid - 1])
            ||  mid % 2  == 1 && nums[mid] == nums[mid + 1]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return nums[mid];
    }
};