/*---------------- Brute Force Approach -------------------- */
// Time Complexity : O(N^2)
// Space Complexity : O(1)

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();

        vector<int> result(n, 0);

        if(k == 0) {
            return result;
        }

        for(int i = 0; i<n; i++) {
            int sum = 0;
            if(k > 0) {
                for(int j = 1; j <= k; j++) {
                    sum += code[(i + j) % n];
                }
            } else {
                for(int j = 1; j <= -k; j++) {
                    sum += code[(i - j + n) % n];
                }
            }
            result[i] = sum;
        }
        return result;
    }
};

/*--------------- Optimized Approach Using Sliding Window (Prefix Sum) ------------------- */
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);

        if(k == 0) {
            return result;
        }

        int sum = 0;
        int start = (k > 0) ? 1 : n+k; // For positive k, start from 1, for negative k, start from n+k.

        // Initialize the sum for the first element
        for(int i = 0; i < abs(k); i++) {
            sum += code[(start + i) % n];
        }

        for(int i = 0; i < n; i++) {
            result[i] = sum;

            // Slide the window: remove the outgoing element and add the incoming element
            sum -= code[(start + i) % n];
            sum += code[(start + i + abs(k)) % n];
        }
        return result;
    }
};