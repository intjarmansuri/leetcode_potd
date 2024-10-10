/* ------------ Approach 1 : Two Pointer
Time Complexity : O(N)
Space Complexity : O(N) ---------------------- */

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();

        vector<int> rightMax(n);
        rightMax[n-1] = nums[n-1];
        
        for(int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], nums[i]);
        }

        int ramp = 0;
        int i = 0;
        int j = 0;

        while(j < n) {
            while(i < j && nums[i] > rightMax[j]) {
                i++;
            }
            ramp = max(ramp, j-i);
            j++;
        }
        return ramp;
    }
};

/* ------------ Approach 2 : Monotonic Stack
Time Complexity : O(N)
Space Complexity : O(N) ---------------------- */

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;

        for(int i = 0; i < n; i++) {
            if(st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }

        int ramp = 0;
        for(int j = n-1; j >= 0; j--) {
            while(!st.empty() && nums[st.top()] <= nums[j]) {
                ramp = max(ramp, j - st.top());
                st.pop();
            }
        }
        return ramp;
    }
};