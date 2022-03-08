class Solution {
public:
    int v[5] = {-1, 0, 1, 0, -1};
    void paint(vector<vector<int>> &grid, queue<pair<int,int>> &pq, int i, int j){
        if(min(i, j)>=0 && max(i, j)<grid.size() && grid[i][j] == 1){
            grid[i][j] = 2;
            pq.push({i, j});
            for(int k = 0; k<4; k++){
                int x = i + v[k];
                int y = j + v[k+1];
                paint(grid, pq, x, y);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
       queue<pair<int,int>>pq;
       int a = 0;
       int n = grid.size();
       int m = grid[0].size(); 
       for(int i = 0; i<n; i++){
           for(int j = 0; j<m; j++){
               if(a == 0 && grid[i][j] == 1){
                   paint(grid, pq, i, j);
                   a++;
               }
           }
       }
       while(!pq.empty()){
           auto t = pq.front();
           pq.pop();
           for(int k = 0; k<4; k++){
               int x = t.first + v[k];
               int y = t.second + v[k+1];
               if(min(x, y) >= 0 && max(x, y) < n){
                  if(grid[x][y] == 1) return grid[t.first][t.second] - 2;
                  if(grid[x][y] == 0){
                      grid[x][y] = grid[t.first][t.second] + 1;
                      pq.push({x, y});
                   }
               } 
           }
       }
       return 0;
    }
};
