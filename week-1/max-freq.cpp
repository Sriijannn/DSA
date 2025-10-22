//https://leetcode.com/problems/majority-element/
#include <vector>
#include <unordered_map>
using namespace std;



//Skipping Brute Force Approach as 
//time Complexity: O(n^2) Space Complexity: O(1)

//Optimized Approach using Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (int i=0; i<nums.size(); i++){
            hash[nums[i]]++;
            if (hash[nums[i]]>nums.size()/2){
                return nums[i];
            }
        }
        return -1;
        
    }
};