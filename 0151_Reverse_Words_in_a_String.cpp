#include <bits/stdc++.h>
using namespace std;

// LeetCode 151: Reverse Words in a String
// Approach: Reverse Entire String + Reverse Individual Words
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.length();
        string ans ="";
        reverse(s.begin(),s.end());
        for(int i =0;i<=n;i++){
            string word ="";
            while(i<n && s[i]!=' '){
                word += s[i];
                i++;
            }
            reverse(word.begin(),word.end());
            if(word.length()>0){
                ans += " "+ word;
            }
           
        }
                return ans.substr(1);
    }
};