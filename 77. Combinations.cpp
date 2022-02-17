class Solution {
public:
    void solve(vector<int> &v, vector<vector<int>> &ans, int start, int end, int n, int k){
        if(end == k){
            ans.push_back(v);
            return;
        }
        for(int i = start; i<n; i++){
           v.push_back(i+1);
           solve(v, ans, i+1, end+1, n, k);
           v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
       vector<vector<int>> ans;
       if(n<k) return ans;
       vector<int> v;
       solve(v, ans, 0, 0, n, k);
       return ans; 
    }
};
