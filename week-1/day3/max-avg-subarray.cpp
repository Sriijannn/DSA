
//https://leetcode.com/problems/maximum-average-subarray-i/
// Time complexity: O(n)
// Space complexity: O(1)
// Sliding window technique is used to find the maximum average subarray of size k.
#include <vector>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxsum = 0;
    
        for (int i=0; i<k; i++){
            maxsum+=nums[i];
        }
        double sum = maxsum;

        for (int left =1; left <nums.size(); left++){
      
            int right = left +k-1;
            if (right >= nums.size()) break;
            sum = sum - nums[left-1] + nums[right];
    
            maxsum = max(maxsum,sum);
        }

        return maxsum/k;

        
    }
};