/*------------- Approach 1 : Using Stack ----------
Time Complexity : O(N)
Space Complexity : O(N)
*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int count = 0;  // UnMatchedClosing ')'

        for(char &ch : s) {
            if(ch == '(') {
                st.push(ch);
            } else if(ch == ')') {
                if(!st.empty()) {
                    st.pop();
                } else {
                    count++;
                }
            }
        }

        return st.size() + count;
    }
};

/*------------- Approach 1 : Without Stack, Greedy ----------
Time Complexity : O(N)
Space Complexity : O(1)
*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int openCount = 0;    // '('
        int unMatchedCount = 0;   // ')'

        for(char &ch : s) {
            if(ch == '(') {
                openCount++;
            } else if(ch == ')') {
                if(openCount > 0) {
                    openCount--;
                } else {
                    unMatchedCount++;
                }
            }
        }

        return openCount + unMatchedCount;
    }
};