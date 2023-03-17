// Given a string s, find the first non-repeating character in it and return its index.
// If it does not exist, return -1.

 

// Example 1:

// Input: s = "leetcode"
// Output: 0
// Example 2:

// Input: s = "loveleetcode"
// Output: 2
// Example 3:

// Input: s = "aabb"
// Output: -1
 

// Constraints:

// 1 <= s.length <= 105
// s consists of only lowercase English letters.

#include <unordered_map>
#include <string>

class Solution {
public:
    int firstUniqChar(const std::string& s) {
        std::unordered_map<char, int> table;
        for (std::size_t i = 0; i < s.size(); ++i) {
            if (table.find(s[i]) != table.end()) {
                table[s[i]] = -1;
            } else {
                table[s[i]] = i;
            }
        }
        for (std::size_t i = 0; i < s.size(); ++i) {
            if (table[s[i]] != -1) {
                return table[s[i]];
            }
        }
        return -1;
    }
};