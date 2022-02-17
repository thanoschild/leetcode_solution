class Solution {
public:
    void solve(vector<int> v, vector<vector<int>> &ans, int k, int n){
        if(v.size() == k && n == 0){
            ans.push_back(v);
            return;
        }
        if(v.size() < k){
            for(int i = v.empty() ? 1 : v.back() +1; i<=9; i++){
                if(n-i<0) break;
                v.push_back(i);
                solve(v, ans, k, n - i);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(v, ans, k, n);
        return ans;
    }
};
