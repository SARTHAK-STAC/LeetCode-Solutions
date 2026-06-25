#include <bits/stdc++.h>
using namespace std;

// LeetCode 240: Search a 2D Matrix II
// Approach: Start from Top-Right Corner
// Time Complexity: O(m + n)
// Space Complexity: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int r = 0, c = m - 1;

        while (r < n && c >= 0) {
            if (matrix[r][c] == target) {
                return true;
            }
            else if (target < matrix[r][c]) {
                c--;
            }
            else {
                r++;
            }
        }

        return false;
    }
};