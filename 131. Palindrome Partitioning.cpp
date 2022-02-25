class Solution {
public:
    bool check(string &s, int i, int j){
        while(i<j){
        if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    void partition(string &s, int start, vector<string> &path, vector<vector<string>> &result){
        int n = s.size();
        if(start == n){
            result.push_back(path);
            return;
        } 
        for(int i = start; i<n; i++){
            if(check(s, start, i)){
                path.push_back(s.substr(start, i - start+1));
                partition(s, i+1, path, result);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
       vector<vector<string>> result;
       vector<string> path;
       if(s.size() == 0) return result;
       partition(s, 0, path, result);
       return result; 
    }
};
