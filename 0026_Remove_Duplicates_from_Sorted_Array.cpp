#include <vector>
using namespace std;

/*
LeetCode 26 - Remove Duplicates from Sorted Array

Approach:
Use the Two Pointers technique.
- Keep one pointer (k) for the position of the next unique element.
- Traverse the array with another pointer.
- When a new unique element is found, place it at index k and increment k.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        if (n <= 1) {
            return n;
        }

        int k = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[k - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};