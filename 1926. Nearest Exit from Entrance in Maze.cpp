class Solution {
public:
    int v[5] = {-1, 0, 1, 0, -1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<int, int>>pq;
        pq.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int moves = 0;
        while(!pq.empty()){
            moves++;
            int l = pq.size();
            for(int a = 0; a<l; a++){
                auto [i, j] = pq.front();
                pq.pop();
                for (int k = 0; k < 4; k++)
                {
                    int x = i + v[k];
                    int y = j + v[k + 1];
                    if (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == '.')
                    {
                        if (x == 0 || y == 0 || x == n - 1 || y == m - 1)
                            return moves;
                        maze[x][y] = '+';
                        pq.push({x, y});
                    }
               }
            }
        }
        return -1;
    }
};
