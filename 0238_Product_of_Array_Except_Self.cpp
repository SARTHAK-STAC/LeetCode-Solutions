#include <vector>
using namespace std;

/*
LeetCode 238 - Product of Array Except Self

Approach:
Use prefix and suffix products without using division.
- First pass: Store the product of all elements to the left of each index.
- Second pass: Traverse from right to left while maintaining a suffix product.
- Multiply the prefix product with the suffix product to get the final answer.

Time Complexity: O(n)
Space Complexity: O(1) Extra Space (excluding the output array)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n, 1);

        // Prefix products
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // Suffix products
        int suffix = 1;
        for (int i = n - 2; i >= 0; i--) {
            suffix *= nums[i + 1];
            ans[i] *= suffix;
        }

        return ans;
    }
};