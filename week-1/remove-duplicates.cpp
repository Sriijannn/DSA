//https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <vector>
using namespace std;    
// Time complexity: O(n)
// Space complexity: O(1)
// Two-pointer technique is used to remove duplicates in-place.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int left = 0;
       int right =0;
       for (int i=0; i<nums.size();i++){
            if (right==nums.size()) break;
            if (nums[left]==nums[right]){
                right++;
            }
            else{
                swap(nums[left+1], nums[right]);
                left++;
                right++;
            }
       }
       return left+1;
    }
};