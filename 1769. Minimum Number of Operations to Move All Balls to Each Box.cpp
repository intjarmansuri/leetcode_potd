/* ---------------------------- Approach : Brutfoce --------------------------*/
// Time Complexity : O(N^2)
// Space Complexity : O(1)

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        vector<int> result(n, 0);

        for(int i = 0; i < n; i++) {

            if(boxes[i] == '1') {
                for(int j = 0; j < n; j++) {

                    result[j] += abs(j-i);
                }
            }   
        }

        return result;
    }
};

/* ---------------------------- Approach : Cumulative Sum --------------------------*/
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        vector<int> result(n, 0);

        int cumValue = 0;
        int cumValueSum = 0;

        // Fine moves for all left balls to index i
        for(int i = 0; i < n; i++) {
            result[i] = cumValueSum;
            cumValue += boxes[i] == '0' ? 0 : 1;
            cumValueSum += cumValue;
        }

        cumValue = 0;
        cumValueSum = 0;
        // Find move for all right balls to index i
        for(int i = n-1; i >= 0; i--) {
            result[i] += cumValueSum;
            cumValue += boxes[i] == '0' ? 0 : 1;
            cumValueSum += cumValue;
        }

        return result;
    }
};