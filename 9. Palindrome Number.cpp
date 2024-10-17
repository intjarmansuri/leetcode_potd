class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0) return false;

        int num = x, rem, ans = 0;

        while(num) {
            rem = num % 10;
            num /= 10;

            if(ans > INT_MAX/10) {
                return 0;
            }

            ans = ans*10 + rem;
        }

        if(ans == x) return true;
        else return false;
    }
};