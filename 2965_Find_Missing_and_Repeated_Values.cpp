#include <vector>
#include <unordered_set>
using namespace std;

/*
LeetCode 2965 - Find Missing and Repeated Values

Approach:
Use an unordered_set to detect the repeated value.
- Traverse the grid and calculate the actual sum.
- Store each number in a hash set.
- If a number already exists in the set, it is the repeated value.
- Compute the expected sum of numbers from 1 to n².
- Derive the missing value using:
    missing = expectedSum + repeated - actualSum

Time Complexity: O(n²)
Space Complexity: O(n²)
*/

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        vector<int> ans;
        unordered_set<int> s;

        int n = grid.size();
        int expectedSum = 0;
        int actualSum = 0;
        int repeated, missing;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                actualSum += grid[i][j];

                if (s.find(grid[i][j]) != s.end()) {
                    repeated = grid[i][j];
                    ans.push_back(repeated);
                }

                s.insert(grid[i][j]);
            }
        }

        expectedSum = (n * n) * (n * n + 1) / 2;

        missing = expectedSum + repeated - actualSum;

        ans.push_back(missing);

        return ans;
    }
};