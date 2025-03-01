// Approach-1 : ( 2-Pass, Two Pointer, Simulation )
// T.C : O(N)
// S.C. : O(1)

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        // Simulation
        for(int i = 0; i < n-1; i++) {
            if(nums[i] == nums[i+1] && nums[i] != 0) {
                nums[i] = nums[i]*2;
                nums[i+1] = 0;
            }
        }

        // Shift all 0' to the end od the array
        int j = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }

        while(j < n) {
            nums[j] = 0;
            j++;
        }
        return nums;
    }
};

// Approach-2 : ( 1-Pass, Two Pointer, Simulation )
// T.C : O(N)
// S.C. : O(1)

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        // Simulation
        int j = 0;
        for(int i = 0; i < n; i++) {
            if(i+1 < n && nums[i] == nums[i+1] && nums[i] != 0) {
                nums[i] = nums[i]*2;
                nums[i+1] = 0;
            }

            if(nums[i] != 0) {
                if(i != j) {
                    swap(nums[i], nums[j]);
                }
                j++;
            }
        }

        return nums;
    }
};