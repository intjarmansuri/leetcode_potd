/* ------------- Approach : 1 Using Sortig ----------- */
/* T.C : O(nlogn), S.C: O(1)  */

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        sort(begin(skill), end(skill));

        int i = 0;
        int j = n - 1;
        int s = skill[i] + skill[j];

        long long chem = 0;

        while(i < j) {
            int currSkill = skill[i] + skill[j];

            if(currSkill != s) {
                return -1;
            }

            chem += (long long)(skill[i]) * (long long)(skill[j]);
            i++;
            j--;
        }
        return chem;
    }
};


/*---------------- Approach : 2  Using  Array ------------- */
// T.C: O(N), S.C : O(1001)

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        vector<int> vec(1001, 0);
        int sum = 0;

        for(int& s : skill) {
            sum += s;
            vec[s]++;
        }

        int teams = n/2;
        if(sum % teams != 0) {
            return -1;
        }

        int target = sum/teams;
        long long chem = 0;

        for(int i = 0; i < n; i++) {
            int currSkill = skill[i];
            int remainSkill = target - currSkill;

            if(vec[remainSkill] <= 0) {
                return -1;
            }

            chem += (long long)(currSkill) * (long long)(remainSkill);

            vec[remainSkill] -= 1;
        }
        return chem/2;
    }
};

