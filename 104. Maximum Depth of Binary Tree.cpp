class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if(!root) return 0;
        queue<pair<TreeNode*, int>> pq;
        int ans = 0;
        pq.push({root, 1});
        while(!pq.empty()){
            auto it = pq.front();
            pq.pop();
            TreeNode* t = it.first;
            int lev = it.second;
            ans = max(ans, lev);
            if(t->left) pq.push({t->left, lev+1});
            if(t->right) pq.push({t->right, lev+1});
        }
        return ans;
    }
};
