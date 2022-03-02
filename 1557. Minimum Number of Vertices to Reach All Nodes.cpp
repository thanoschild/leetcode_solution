class Solution {
public:
   
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans, indeg(n);
        for(auto it : edges){
            indeg[it[1]]++;
        }
        for(int i=0; i<n; i++){
            if(indeg[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};
