//https://leetcode.com/problems/sort-colors/submissions/1809454529/


#include <vector>
using namespace std;    
// Time complexity: O(n^2)
// Space complexity: O(1)       
// Bubble sort algorithm is used to sort the colors in-place.
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++){
            for (int j= 0; j<nums.size()-i-1; j++){
                if (nums[j]>nums[j+1]){
                    swap (nums[j], nums[j+1]);
                }
                else continue;
            }
        }
        
    }
};

// Time complexity: O(n)
// Space complexity: O(1)
// Dutch National Flag algorithm is used to sort the colors in-place.
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};


//The dutch national flag algorithm is an efficient way to sort an array with three distinct values (0, 1, and 2 in this case) in a single pass. The algorithm maintains three pointers: low, mid, and high. The low pointer tracks the position where the next 0 should be placed, the mid pointer scans through the array, and the high pointer tracks the position where the next 2 should be placed. By swapping elements as needed, the algorithm ensures that all 0s are moved to the front, all 1s remain in the middle, and all 2s are moved to the end of the array. This approach achieves a time complexity of O(n) and a space complexity of O(1), making it very efficient for this problem.

// Example usage:
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
