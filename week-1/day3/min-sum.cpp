//https://leetcode.com/problems/minimum-size-subarray-sum/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)
// Sliding window approach to find the minimum length of a contiguous subarray
// of which the sum is at least target. 

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int i=0;
        int start = 0;
        int sum = nums[0];
        int count = 1;
        int min_count = INT_MAX;
        if (nums[0] >= target) return 1;

        while (i < nums.size()) {
            if (sum < target) {
                i++;
                if (i >= nums.size()) break;
                sum = sum + nums[i];
                count++;
            } else {
                min_count = min(min_count, count);
                sum = sum - nums[start];
                count--;
                start++;
            }
        }
        if (min_count == INT_MAX) return 0;
        return min_count;
    }
};


// Another approach:
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }
};


