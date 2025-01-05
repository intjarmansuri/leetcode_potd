// Time Comeplexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_set<char> unq_letters;

        for(char &ch : s) {
            unq_letters.insert(ch);
        }

        int result = 0;

        for(char letter : unq_letters) {
            int firstIdx = -1;
            int lastIdx = -1;

            for(int i = 0; i < n; i++) {
                if(s[i] == letter) {
                    
                    if(firstIdx == -1) {
                        firstIdx = i;
                    }

                    lastIdx = i;
                }
            }

            unordered_set<char> st;
            for(int middle = firstIdx + 1; middle <= lastIdx - 1; 
            middle++){
                st.insert(s[middle]);
            }
            result += st.size();   
        }
        return result;
    }
}; 