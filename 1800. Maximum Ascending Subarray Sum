/* --------------------------- Approach : Simple If Else ---------------------- */
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        
        int sum = nums[0];
        int maxSum = nums[0];

        for(int i = 1; i < n; i++) {

            if(nums[i] > nums[i-1]) {
                sum += nums[i];
                maxSum = max(maxSum, sum);
            } 
            else {
                sum = nums[i];
            }
        }
        return maxSum;
    }
};