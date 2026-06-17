#include <bits/stdc++.h>
using namespace std;

// LeetCode 31: Next Permutation
// Approach: Pivot + Swap + Reverse Suffix
// Time Complexity: O(n)
// Space Complexity: O(1)


class Solution {
public:
    void nextPermutation(vector<int>& s) {
        int pivot =-1, n = s.size();

        for(int i = n-2; i>=0;i--){
            if(s[i]<s[i+1]){
                pivot = i;
                break;
            }
        }
        if(pivot ==-1){
            reverse(s.begin(),s.end());
            return;
        }
        for(int i =n-1;i>=0;i--){
            if(s[i]>s[pivot]){
                swap(s[i],s[pivot]);
                break;
            }
        }
        int i = pivot+1, j = n-1;
            while(i<=j){
                swap(s[i++],s[j--]);
            }
                }
    };