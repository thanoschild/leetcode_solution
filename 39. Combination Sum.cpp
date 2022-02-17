class Solution {
public:
    void solve(int i, vector<int> &v, vector<vector<int>> &ans, int target, vector<int> &arr)
    {
     if(arr.size() == i)
     {
         if(target == 0)
         ans.push_back(v);
         return;
     }
     if(target >= arr[i])
     {
         v.push_back(arr[i]);
         solve(i, v, ans, target-arr[i], arr);
         v.pop_back();
     }
     solve(i+1, v, ans, target, arr);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(0, v, ans, target, arr);
        return ans;
    }
};
