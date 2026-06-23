#include <vector>
#include <climits>
using namespace std;

/*
LeetCode 53 - Maximum Subarray

Approach:
Use Kadane's Algorithm.
- Maintain a running sum (currSum).
- Update the maximum sum found so far (maxSum).
- If currSum becomes negative, reset it to 0 since a negative sum
  would only decrease the sum of any future subarray.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;

        for (int val : nums) {
            currSum += val;
            maxSum = max(maxSum, currSum);

            if (currSum < 0) {
                currSum = 0;
            }
        }

        return maxSum;
    }
};