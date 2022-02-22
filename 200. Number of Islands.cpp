int arr[5] = {-1, 0, 1, 0, -1};
class Solution {
public:
   void getcomp(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j, int n, int m){
       visited[i][j] = true;
       for(int k=0; k<4; k++){
           int a = i + arr[k];
           int b = j + arr[k+1];
           if (a >= 0 && a < n && b >= 0 && b < m && grid[a][b] == '1' && !visited[a][b]){
              getcomp(grid, visited, a, b, n, m);
           }
       }
   }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    getcomp(grid, visited, i, j, n, m);
                    count++;
                }
            }
        }
        return count;
    }
};
