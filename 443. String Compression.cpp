/* ---------------- Approach Two Pointer -------------- */
// Time Complexity : O(N)
// Space Complexity : O(1)


class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0;
        int i = 0;

        while(i < n) {
            int count = 0;
            char ch = chars[i];

            while(i < n && chars[i] == ch) {
                count++;
                i++;
            }

            chars[index++] = ch;

            if(count > 1) {
                string countStr = to_string(count);

                for(char c : countStr) {
                    chars[index++] = c;
                }
            }
        }
        return index;
    }
};