class Solution {
public:
    vector<int> parent, sz;
    int find_set(int x){
        if(parent[x] == x) return x;
        return parent[x] = find_set(parent[x]);
    }
    bool find_union(int x, int y){
        int a = find_set(x);
        int b = find_set(y);
        if(a == b) return false;
        if(sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
       parent.resize(n), sz.resize(n);
       for(int i=0; i<n; i++){
           parent[i] = i;
           sz[i] = 1;
       }
       int count = 0;
       for(int i = 0; i<n; i++){
           for(int j = i+1; j<n; j++){
               if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                   if(find_union(i, j)) count++;
               }
           }
       }
       return count;
    }
};
