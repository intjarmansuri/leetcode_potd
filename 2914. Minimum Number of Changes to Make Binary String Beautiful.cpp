/* -------------- Approach-1 (Simple iterate and count and keep track) -------------*/
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    int minChanges(string s) {
        int n = s.length();

        char ch = s[0];
        int count = 0;

        int changes = 0;

        for(int i = 0; i<n; i++) {
            if(s[i] == ch) {
                count++;
                continue;
            }

            // curr character is not equal to ch
            if(count % 2 == 0) {
                count = 1;
            } else {
                changes += 1;
                count = 0;
            }
            ch = s[i];
        }
        return changes;
    }
};


/* -------------- Approach-2 (Simple iterate and count and keep track) -------------*/
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        
        int changes = 0;

        for(int i = 0; i < n; i+=2) {
            if(s[i] != s[i+1]) {
                changes++;
            }
        }
        return changes;
    }
};