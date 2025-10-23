//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
#include <vector>
#include <algorithm>
using namespace std;


//this is a sliding window approach
// Time Complexity: O(k)
// Space Complexity: O(1)
//but this would work only when we are allowed to take only from one side either left or right.
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
     
        int SIZE = k;
   
        int maxSum = 0;
        while (k!=0){
            maxSum = maxSum + cardPoints[k-1];
            k=k-1;
        }
        for (int left =1;left <cardPoints.size();left++ ){
            int right =left+SIZE-1;
     
            if (right == cardPoints.size()) break;
            int newSum = maxSum - cardPoints[left-1] + cardPoints[right];
            if (maxSum<newSum) maxSum=newSum;
        }
        return maxSum;
        
    }
};


//now lets consider the case where we can take from both sides.

//this can be one of the approaches
// Time Complexity: O(3k)
// Space Complexity: O(k)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector <int>start(k+1,0);
        vector <int>end(k+2,0);
        int maxSum=0;
        for (int i=0; i<k;i++){
            start[i+1]=cardPoints[i]+start[i];
        }
        for (int i=0; i<k;i++){
            end[k-1]=cardPoints[cardPoints.size()-i-1]+end[i];
            
        }

        for (int i=0; i<=k; i++){
            int sum = start[i]+end[k-i];
            maxSum= max(maxSum, sum);
        }
        
        return maxSum;
        
    }
};

//This is the most optimised approach using sliding window
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
     
        int SIZE = k;
        int right = cardPoints.size();
   
        int maxSum = 0;
        while (k!=0){
            maxSum = maxSum + cardPoints[k-1];
            k=k-1;
        }
        int newSum = maxSum;
        for (int i =0;i<SIZE;i++ ){
            newSum = newSum - cardPoints[SIZE-i-1] + cardPoints[right-1-i];
            maxSum = max(maxSum, newSum);

        }
        return maxSum;
        
    }
};

