class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        unordered_set<char> allowedSet(begin(allowed), end(allowed));
        int count = 0;

        for(string word : words)  {
            bool isConsistent = true;

            for(char ch : word) {
                if(allowedSet.find(ch) == allowedSet.end()) {
                    isConsistent = false;
                    break;
                }
            }

            if(isConsistent) {
                count++;
            }
        }
        return count;
    }
};