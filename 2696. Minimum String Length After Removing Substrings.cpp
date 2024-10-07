/*--------------- Approach : 1 Using Stack --------------- */

class Solution {
public:
    int minLength(string s) {
        stack<char> st;

        for(char ch : s) {

            if(!st.empty() && 
               ((st.top() == 'A' && ch == 'B') || (st.top() == 'C' && ch == 'D'))) {
                st.pop();  
            } else {
                st.push(ch);
            }
        }
        return st.size();
    }
};

/*--------------- Approach : 1 Using Two Pointer --------------- */

class Solution {
public:
    int minLength(string s) {
        int n = s.length();
        int i = 0;  //write
        int j = 1;  // read

        while(j < n) {
            if( i < 0) {
                i++;
                s[i] = s[j];
            } 
            else if((s[i] == 'A' && s[j] =='B') || 
            (s[i] == 'C' && s[j] == 'D')) {
                i--;
            } else {
                i++;
                s[i] = s[j];
            }
            j++;
        }
        return i+1;
    }
};