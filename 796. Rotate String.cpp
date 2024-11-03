/* ---------------- Approach-1 (Brute Force Check all rotations) ------------------  */
//Time Complexity : O(n^2)
//Space Complexity : O(1)


class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();

        if(n != m) 
            return false;

        for(int i = 1; i <= n; i++) {

            rotate(begin(s), begin(s)+1, end(s));

            if(s == goal)
                return true;
        }
        return false;
    }
};

/* ---------------- Approach-2 (Concatenation with itself contains all possible rotations) ------------------  */
//Time Complexity : O(n)
//Space Complexity : O(1)

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();

        if(n != m)
            return false;

        if((s+s).find(goal) != string::npos) {
            return true;
        }

        return false;
    }
};