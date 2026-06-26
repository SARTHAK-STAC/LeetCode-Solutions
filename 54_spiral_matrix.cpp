#include <vector>
using namespace std;

/*
LeetCode 54 - Spiral Matrix

Approach:
Use four boundaries to traverse the matrix layer by layer.
- startingRow (sr) and endingRow (er) represent the current top and bottom rows.
- startingColumn (sc) and endingColumn (ec) represent the current left and right columns.
- Traverse in four directions:
  1. Left to Right
  2. Top to Bottom
  3. Right to Left (if top != bottom)
  4. Bottom to Top (if left != right)
- After completing one layer, move all four boundaries inward.

Time Complexity: O(m × n)
Space Complexity: O(1) (excluding the output vector)
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        int sr = 0, er = m - 1;
        int sc = 0, ec = n - 1;

        vector<int> ans;

        while (sr <= er && sc <= ec) {

            // Left to Right
            for (int i = sc; i <= ec; i++) {
                ans.push_back(matrix[sr][i]);
            }

            // Top to Bottom
            for (int j = sr + 1; j <= er; j++) {
                ans.push_back(matrix[j][ec]);
            }

            // Right to Left
            if (sr != er) {
                for (int i = ec - 1; i >= sc; i--) {
                    ans.push_back(matrix[er][i]);
                }
            }

            // Bottom to Top
            if (sc != ec) {
                for (int j = er - 1; j > sr; j--) {
                    ans.push_back(matrix[j][sc]);
                }
            }

            sr++;
            er--;
            sc++;
            ec--;
        }

        return ans;
    }
};