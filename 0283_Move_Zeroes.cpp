#include <vector>
#include <algorithm>
using namespace std;

/*
LeetCode 283 - Move Zeroes

Approach:
Use Two Pointers.
- Pointer i tracks the position where the next non-zero element should be placed.
- Pointer j traverses the array.
- Whenever a non-zero element is found, swap it with the element at i and increment i.
- This moves all non-zero elements to the front while maintaining their relative order.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};