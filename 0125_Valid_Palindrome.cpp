#include <bits/stdc++.h>
using namespace std;

// LeetCode 125: Valid Palindrome
// Approach: Two Pointers + Ignore Non-Alphanumeric Characters
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool isPalindrome(string s) {
        
        int st = 0, end = s.length()-1;
        while(st<end){
            if(!isalnum(s[st])){
                st++; continue;
            }
            if(!isalnum(s[end])){
                end--;continue;
            }

            if(tolower(s[st])!= tolower(s[end])){
                return false;
            }
            st++, end--;
        }
        return true;
    }

};