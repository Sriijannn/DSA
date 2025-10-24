//https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <string>
#include <vector>
using namespace std;

// Time complexity: O(n^2)
// Space complexity: O(1)
// Brute force approach to find the length of the longest substring without repeating characters.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxl = 0;

        for (int i = 0; i < s.size(); i++) {
            vector<int> seen(256, 0); 
            int temp = 0;

            for (int j = i; j < s.size(); j++) {
                if (seen[s[j]]) { 
                    break;
                }
                seen[s[j]] = 1;
                temp++;
            }
            maxl = max(maxl, temp);
        }

        return maxl;
    }
};


// Optimized approach using sliding window technique
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1); 
        int maxLen = 0;
        int start = 0; 

        for (int end = 0; end < s.size(); end++) {
            
            if (lastIndex[s[end]] >= start) {
                start = lastIndex[s[end]] + 1;
            }
            lastIndex[s[end]] = end; 
            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};
