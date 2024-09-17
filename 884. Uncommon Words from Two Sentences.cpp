class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;

        auto countWords = [&](string s) {
            stringstream ss(s);
            string word = "";
            while(ss >> word) {
                mp[word]++;
            }
        };

        countWords(s1);
        countWords(s2);

        vector<string> result;

        for(auto& entry: mp) {
            if(entry.second == 1) {
                result.push_back(entry.first);
            }
        }
        return result;
    }
};