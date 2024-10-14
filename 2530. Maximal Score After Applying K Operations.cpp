/* --------------- Using Maxheap
Time Complexity : O(n + klog n)
Space Complexity : O(N) ----------------- */

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;

        priority_queue<int> pq(begin(nums), end(nums));

        while(k--) {
            int maxElement = pq.top();
            pq.pop();

            ans += maxElement;
            maxElement = ceil(maxElement/3.0);

            pq.push(maxElement);
        }
        return ans;
    }
};