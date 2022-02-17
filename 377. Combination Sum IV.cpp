class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
       vector<unsigned int> dp(target+1, 0);
       dp[0] = 1;
       for(int i=1; i<=target; i++){
           for(auto it : nums){
               if(it <= i) dp[i] += dp[i-it];
           }
       } 
       return dp[target];
    }
};
