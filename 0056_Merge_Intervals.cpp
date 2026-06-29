#include <vector>
#include <algorithm>
using namespace std;

/*
LeetCode 56 - Merge Intervals

Approach:
- Sort the intervals based on their starting time.
- Add the first interval to the answer.
- Traverse the remaining intervals:
    - If the current interval overlaps with the last interval
      in the answer, merge them.
    - Otherwise, add the current interval to the answer.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i][0] <= ans.back()[1]) {

                ans.back()[1] = max(ans.back()[1], intervals[i][1]);

            } else {

                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};