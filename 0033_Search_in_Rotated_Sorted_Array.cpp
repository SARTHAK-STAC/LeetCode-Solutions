#include <vector>
using namespace std;

/*
LeetCode 33 - Search in Rotated Sorted Array

Approach:
Use Modified Binary Search.
- At every step, determine which half of the array is sorted.
- If the target lies within the sorted half, search there.
- Otherwise, search in the other half.
- Repeat until the target is found or the search space becomes empty.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int st = 0;
        int end = nums.size() - 1;

        while (st <= end) {

            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Left half is sorted
            if (nums[st] <= nums[mid]) {

                if (target >= nums[st] && target <= nums[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            }

            // Right half is sorted
            else {

                if (target >= nums[mid] && target <= nums[end]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};