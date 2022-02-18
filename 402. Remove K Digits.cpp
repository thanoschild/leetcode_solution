// two approach first one is using stack and the second one is without use of stack
class Solution {
public:
    string removeKdigits(string num, int k) {
    //   int n = num.size();
    //   stack<char> st;
    //   st.push(num[0]);
    //   for(int i=1; i<n; i++){
    //       while(!st.empty() && num[i] < st.top() && k>0){
    //           k --;
    //           st.pop();
    //       }
    //       st.push(num[i]);
    //       if(st.size() == 1 && num[i] == '0'){
    //           st.pop();
    //       }
    //   } 
    //   while(!st.empty() && k){
    //     st.pop();
    //     k--;
    //   }
    //   if(st.size() == 0)
    //   return "0";
    //   string ans = "";
    //   while(!st.empty()){
    //       ans += st.top();
    //       st.pop();
    //   }
    //   reverse(ans.begin(), ans.end());
    //   return ans;

    int n = num.size();
    string s = "";
    s += num[0];
    for(int i=1; i<n; i++){
        while(s.size() != 0 && num[i] < s.back() && k>0){
            s.pop_back();
            k--;
        }
        if(s.size() >= 1 || num[i] != '0'){
            s += num[i];
        }
    }
    while(s.size() && k){
        s.pop_back();
        k--;
    }
    return s.size() == 0 ? "0" : s;
    }
};
