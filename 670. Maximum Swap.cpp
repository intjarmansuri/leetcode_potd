/* ------------ Approach - 1: Greedy 
Time Complexity : O(N)
Space Complexity : O(N) -------------------- */

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();

        vector<int>maxRight(n);
        maxRight[n-1] = n-1;

        for(int i = n-2; i >= 0; i--) {
            int rightMaxIdx = maxRight[i+1];
            int rightMaxEle = s[rightMaxIdx];

            maxRight[i] = (s[i] > rightMaxEle) ? i : rightMaxIdx;
        }

        for(int i = 0; i < n; i++) {
            int maxRightIdx = maxRight[i];
            int maxRightEle = s[maxRightIdx];

            if(s[i] < maxRightEle) {
                swap(s[i], s[maxRightIdx]);
                return stoi(s);
            }
        }
        return num;
    }
};

/* ------------ Approach - 2: Greedy 
Time Complexity : O(N)
Space Complexity : O(10) -------------------- */

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();

        // Store the last occurrence of each digit (0-9)
        vector<int> maxRight(10, -1);

        // Fill the maxRight array with the latest index of each digit
        for (int i = 0; i < n; i++) {
            int idx = s[i] - '0';
            maxRight[idx] = i;
        }

        // Traverse the number and find the first position where a swap can increase the value
        for (int i = 0; i < n; i++) {
            char currChar = s[i];
            int currDigit = currChar - '0';

            // Check if there is a larger digit that appears later
            for (int digit = 9; digit > currDigit; digit--) {
                if (maxRight[digit] > i) {
                    swap(s[i], s[maxRight[digit]]);
                    return stoi(s); // Return the new number after swap
                }
            }
        }

        // Return the original number if no swap is possible
        return num;
    }
};