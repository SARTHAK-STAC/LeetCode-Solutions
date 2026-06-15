#include <vector>
#include <string>
using namespace std;


// LeetCode 443: String Compression
// Approach: Two Pointers + Counting Consecutive Characters
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int compress(vector<char>& chars) {
        

        int idx =0;
        int n = chars.size();
        for(int i =0;i<n;i++){
            int ch = chars[i];
            int count =0;
            while(i<n && chars[i]==ch){
                count++; i++;
            }
            if(count==1){
                chars[idx++] = ch;
            }
            else{
                chars[idx++] = ch;
                string str = to_string(count);
                for(char dig:str){
                    chars[idx++] = dig;
                }
            }
            i--;
        }
        chars.resize(idx);
        return idx;
    }
};