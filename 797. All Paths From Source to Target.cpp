class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<vector<int>> &graph, int i, vector<int> &v, int n){
        v.push_back(i);
        if(i == n-1) {
            ans.push_back(v);
            return ;
        }
        for(auto it : graph[i]){
               dfs(graph, it, v, n);
               v.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       int n = graph.size();
       vector<bool> visited(n, 0);
       vector<int> v;
       dfs(graph, 0, v, n); 
       return ans;
    }
};
