class Solution
{
public:
    int maxlen(vector<string> &s){
        int ans = 0;
        for(string str : s){
            ans = max(ans, int(str.size()));
        }
        return ans;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        if(wordDict.size() == 0) return false;
        const int n = s.size(), m = maxlen(wordDict);
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i = 1; i<=s.size(); i++){
            for(int j = i-1; j>=0 && j - i<=m; j--){
              if(dp[j]){
                  string str = s.substr(j, i - j);
                  if(st.find(str) != st.end()){
                      dp[i] = true;
                      break;
                  }
              }
            }
        }
        return dp[n];
     }
};
