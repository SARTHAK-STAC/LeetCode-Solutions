#include <vector>
using namespace std;

/*

Approach:
Use XOR operation.
- a ^ a = 0
- a ^ 0 = a
All duplicate numbers cancel out, leaving only the unique number.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int val : nums) {
            ans ^= val;
        }

        return ans;
    }
};