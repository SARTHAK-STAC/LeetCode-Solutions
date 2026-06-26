#include <vector>
#include <algorithm>
using namespace std;

/*
LeetCode 11 - Container With Most Water

Approach:
Use the Two Pointers technique.
- Place one pointer at the beginning and one at the end of the array.
- Calculate the area formed by the two lines.
- Update the maximum area found so far.
- Move the pointer with the smaller height inward since moving the taller
  pointer cannot increase the area while the width decreases.
- Repeat until both pointers meet.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int lp = 0;
        int rp = height.size() - 1;

        while (lp < rp) {
            int width = rp - lp;
            int ht = min(height[lp], height[rp]);
            int area = width * ht;

            ans = max(ans, area);

            height[lp] < height[rp] ? lp++ : rp--;
        }

        return ans;
    }
};