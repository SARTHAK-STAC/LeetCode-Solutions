#include <vector>
using namespace std;

/*
LeetCode 27 - Remove Element

Approach:
Use a pointer to track the position where the next valid
(non-val) element should be placed.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int v = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[v] = nums[i];
                v++;
            }
        }

        return v;
    }
};