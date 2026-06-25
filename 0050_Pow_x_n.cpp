#include <bits/stdc++.h>
using namespace std;

// LeetCode 50: Pow(x, n)
// Approach: Binary Exponentiation (Fast Power)
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    double myPow(double x, int n) {
        long long exponent = n;
        double ans = 1.0;

        // Handle negative exponent
        if (exponent < 0) {
            x = 1 / x;
            exponent = -exponent;
        }

        // Binary Exponentiation
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                ans *= x;
            }

            x *= x;
            exponent /= 2;
        }

        return ans;
    }
};