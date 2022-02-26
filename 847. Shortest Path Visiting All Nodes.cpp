class Solution
{
public:
    int solve(vector<vector<int>> &graph){
        int n = graph.size();
        queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> st;
        int check = (1<<n) - 1;
        for(int i=0; i<n; i++){
            int mask = 1<<i;
            pq.push({i, {0, mask}});
            st.insert({i, mask});
        }
        while(!pq.empty()){
           auto t = pq.front(); 
           pq.pop();
           int sc = t.first;
           int dist = t.second.first;
           int mask = t.second.second;
           for(auto it : graph[sc]){
               int newmask = (mask | (1<<it));
               if(newmask == check) return dist + 1;
               if(st.find({it, newmask}) != st.end()) continue;
               pq.push({it, {dist+1, newmask}});
               st.insert({it, newmask});
           } 
        }
        return 0;
    }
    int shortestPathLength(vector<vector<int>> &graph)
    {
        if(graph.size() == 2 || graph.size() == 1) return graph.size() - 1;
        return solve(graph);
    }
};
