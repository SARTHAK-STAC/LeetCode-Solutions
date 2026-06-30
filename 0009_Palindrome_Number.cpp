#include <vector>
using namespace std;

/*
LeetCode 9 - Palindrome Number

Approach:
Reverse the given number and compare it with the original number.
- Store the original number in a temporary variable.
- Reverse the digits one by one.
- If the reversed number is equal to the original number,
  the number is a palindrome.

Time Complexity: O(log10(n))
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0) {
            return false;
        }

        long long rev = 0;
        int temp = x;

        while (x > 0) {
            int rem = x % 10;
            rev = rev * 10 + rem;
            x /= 10;
        }

        return temp == rev;
    }
};