// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
// it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

 

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:

// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.
 

// Constraints:

// 1 <= s.length <= 2 * 105
// s consists only of printable ASCII characters.


#include <string>

class Solution {
public:
    bool isPalindrome(const std::string& s) {
        int i = -1;
        int len = 0;

        while (s[++i]) {
            if (isalnum(s[i])) {
                ++len;
            }
        }
        std::string str(len, '\0');
        i = -1;
        int j = 0;
        while (s[++i]) {
            if (isalnum(s[i])) {
                str[j] = tolower(s[i]);
                ++j;
            }
        }
        i = -1;
        while (++i < --j) {
            if (str[i] != str[j]) {
                return false;
            }
        }
        return true;
    }
};