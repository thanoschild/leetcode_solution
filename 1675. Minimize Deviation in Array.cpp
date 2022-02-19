class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int ans = INT_MAX, minval = INT_MAX;
        priority_queue<int> pq;
        for(auto it : nums){
            it = it%2 ? it*2 : it;
            pq.push(it);
            minval = min(minval, it);
        }
        while(pq.top() %2 == 0){
            ans = min(ans, pq.top() - minval);
            minval = min(minval, pq.top()/2);
            pq.push(pq.top()/2);
            pq.pop();
        }
        return ans = min(ans, pq.top() - minval);
    }
};
