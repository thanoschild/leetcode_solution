class Solution {
    string sortstr(string s){
        int count[26] = {0};
        for(char n : s){
          count[n - 'a']++;
        }
        string t ="";
        for(int i=0; i<26; i++){
            t += count[i] + 'a';
        }
        return t;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        unordered_map<string, vector<string>>mp;
        for(auto it : str){
            //string s = it;
            //sort(s.begin(), s.end());
            mp[sortstr(it)].push_back(it);
        }
        vector<vector<string>> ans;
        for(auto it : mp){
           ans.push_back(it.second);
        }
        return ans;
    }
};
