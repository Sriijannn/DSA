//https://leetcode.com/problems/two-sum/description/

#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
   

        for ( int i=0; i<nums.size(); i++){
            for (int j=i+1; j<nums.size(); j++){// j=i+1 to avoid using the same element
                if (nums[i]+nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};

/*
Optimized Approach using Hash Map 
Time Complexity: O(n)
Space Complexity: O(n)
Here we use an unordered_map to store the complement and its index as we iterate through the array.
if we find the complement in the map, we return the indices.
Else we store the current number and its index in the map.
*/
#include <unordered_map>    
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map; // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i};
            }
            num_map[nums[i]] = i;
        }
        return {};
    }
};


