// the overall time complexity is O(n log 3) ≈ O(n).

class Solution {
public:
    typedef pair<int, char> P;
    
    string longestDiverseString(int a, int b, int c) {
        priority_queue<P> pq;    // MaxHeap to store count and character

        // Push the characters with their count in the priority queue
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});

        string result = "";

        // Loop until the priority queue is empty
        while(!pq.empty()) {
            // Get the character with the largest count
            int currCount = pq.top().first;
            char currChar = pq.top().second;
            pq.pop();

            // If the last two characters in the result are the same as the current character
            if(result.length() >= 2 && result[result.length()-1] == currChar && result[result.length()-2] == currChar) {
                // If the priority queue is empty, we can't add any more characters
                if(pq.empty()) {
                    break;
                }

                // Get the next character with the second largest count
                int nextCount = pq.top().first;
                char nextChar = pq.top().second;
                pq.pop();

                // Add the next character to the result
                result.push_back(nextChar);
                nextCount--;

                // If the count of nextChar is still greater than 0, push it back to the queue
                if(nextCount > 0) {
                    pq.push({nextCount, nextChar});
                }

                // Push back the current character as we couldn't use it earlier
                pq.push({currCount, currChar});
            } else {
                // Otherwise, add the current character to the result
                result.push_back(currChar);
                currCount--;

                // If the count of currChar is still greater than 0, push it back to the queue
                if(currCount > 0) {
                    pq.push({currCount, currChar});
                }
            }
        }

        return result;
    }
};
