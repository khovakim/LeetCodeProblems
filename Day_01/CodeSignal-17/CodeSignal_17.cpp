// You are given an array of integers. On each move you are allowed to increase exactly one of its element by one. 
//Find the minimal number of moves required to obtain a strictly increasing sequence from the input.

// Example

// For inputArray = [1, 1, 1], the output should be
// solution(inputArray) = 3.

// Input/Output

// [execution time limit] 0.5 seconds (cpp)

// [input] array.integer inputArray

// Guaranteed constraints:
// 3 ≤ inputArray.length ≤ 105,
// -105 ≤ inputArray[i] ≤ 105.

// [output] integer

// The minimal number of moves needed to obtain a strictly increasing sequence from inputArray.
// It's guaranteed that for the given test cases the answer always fits signed 32-bit integer type.

#include <vector>

int solution(std::vector<int> inputArray) {
    int count = 0;
    int i = 1;
    while (i < inputArray.size()) {
        if (inputArray[i - 1] < inputArray[i]) {
            ++i;
        } else {
            ++count;
            ++inputArray[i];
        }
    }
    return count;
}
