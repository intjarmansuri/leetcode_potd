// Approach-1 : (Brutforce)
// T.C : O(N^2)
// S.C : O(1)

class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;
        while(num > 0) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int result = -1;

        for(int i = 0; i < n; i++) {
            int digitSumi = getDigitSum(nums[i]);

            for(int j = i+1; j < n; j++) {
                int digitSumj = getDigitSum(nums[j]);

                if(digitSumi == digitSumj) {
                    result = max(result, nums[i] + nums[j]);
                }
            }
        }
        return result;
    }
};

// Approach-2 : (Using HashMap)
// T.C : O(N*K)
// S.C : O(N)

class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;
        while(num > 0) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int result = -1;

        unordered_map<int, int>mp;

        for(int i = 0; i < n; i++) {
            int digitSum = getDigitSum(nums[i]);

            if(mp.count(digitSum)) {
                result = max(result, nums[i] + mp[digitSum]);
            }

            mp[digitSum] = max(mp[digitSum], nums[i]);
        }
        return result;
    }
};