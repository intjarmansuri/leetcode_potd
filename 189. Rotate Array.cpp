// Approach-1 : (Brutforce)
// T.C : O(N)
// S.C : O(N)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> temp(n);

        for(int i = 0; i < n; i++) {

            temp[(i+k) % n] = nums[i];
        }
        nums = temp;
    }
};

// Approach-2 : (Reverse Method)
// T.C : O(N)
// S.C : O(1)

class Solution {
public:
    void reverseArray(vector<int>& nums, int start, int end) {
        while(start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;

        reverseArray(nums, 0, n-1);
        reverseArray(nums, 0, k-1);
        reverseArray(nums, k, n-1);
    }
};