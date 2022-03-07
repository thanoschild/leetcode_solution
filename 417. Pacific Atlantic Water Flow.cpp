class Solution {
public:
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j){
        vector<int> v = {-1, 0, 1, 0, -1};
        int n = grid.size();
        int m = grid[0].size();
        visited[i][j] = true;
        for(int k = 0; k<4; k++){
            int x = i + v[k];
            int y = j + v[k+1];
            if(x>=0 && x<n && y>=0 && y<m && !visited[x][y]){
                if(grid[x][y] >= grid[i][j]) dfs(grid, visited, x, y);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
       vector<vector<int>> ans;
       int n = grid.size();
       int m = grid[0].size();
       if(m == 0 || n == 0) return ans;
       vector<vector<bool>> pacific(n, vector<bool> (m, 0));
       vector<vector<bool>> atlantic(n, vector<bool>(m, 0));

       for(int i = 0; i<n; i++){
           dfs(grid, pacific, i, 0);
           dfs(grid, atlantic, i, m-1);
       }
       for(int j = 0; j<m; j++){
           dfs(grid, pacific, 0, j);
           dfs(grid, atlantic, n -1, j);
       }
       for(int i = 0; i<n; i++){
           for(int j = 0; j<m; j++){
               if(pacific[i][j] && atlantic[i][j]) ans.push_back({i, j});
           }
       }
       return ans;
    }
};
