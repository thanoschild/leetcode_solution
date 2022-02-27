class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
      if(!root) return 0;
       queue<pair<TreeNode*, int>>pq; 
       pq.push({root, 0});
       int ans = 1;
       while(!pq.empty()){
           int n = pq.size();
           int idx = pq.front().second;
           int first, last;
           for(int i=0; i<n; i++){
               TreeNode* temp = pq.front().first;
               long long curr = pq.front().second-idx;
               pq.pop();

               if(i == 0) first = curr;
               if(i == n-1) last = curr;
        
               if(temp->left) pq.push({temp->left,  long(curr*2+1)});
               if(temp->right) pq.push({temp->right, long(curr*2 + 2)});
           }
           ans = max(ans, last-first + 1);
       }
       return ans;
    }
};
