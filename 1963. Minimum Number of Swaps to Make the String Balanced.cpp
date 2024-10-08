/* ---------------- Approch 1 : Using Stack------------
Time Complexity : O(N)
Space Complexity : O(N)
*/

class Solution {
public:
    int minSwaps(string s) {
        stack<int> st;

        for(char &ch : s) {
            if(ch == '[') {
                st.push(ch);
            } 
            else if(!st.empty()) {
                st.pop();
            }
        }
        return (st.size() + 1)/2;
    }
};


/* ---------------- Approch 1 : Greedy------------
Time Complexity : O(N)
Space Complexity : O(1)
*/

class Solution {
public:
    int minSwaps(string s) {
        int balance = 0, maxImBalance = 0;

        for(char& ch : s) {
            if(ch == '[') {
                balance++;
            } else {
                balance--;
            }

            if(balance < 0) {
                maxImBalance = max(maxImBalance, -balance);
            }
        }
        return (maxImBalance + 1)/2;
    }
};