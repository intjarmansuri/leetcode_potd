/* ---------------- Approach : String ----------------- */
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    bool isCircularSentence(string sentence) {
        
        // Ensure the sentence has at least one character
        if(sentence.empty())
            return false;
        
        // Check the circular condition between the last and first character
        if(sentence.back() != sentence[0])
            return false;

        int n = sentence.length();

        for(int i = 0; i < n; i++) {
            // If a space is found, check if the current word's last character matches the next word's first character
            if(sentence[i] == ' ') {
                if(i + 1 < n && sentence[i-1] != sentence[i+1])
                    return false;
            }
        }
        return true;
    }
};