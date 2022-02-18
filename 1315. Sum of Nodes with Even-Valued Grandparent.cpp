class Solution {
public:
    void solve(int &ans, bool parent, bool gparent, TreeNode* root){
        if(!root) return;
        if(gparent) ans += root->val;
        solve(ans, root->val%2 == 0, parent, root->left);
        solve(ans, root->val%2 == 0, parent, root->right);
    }
    int sumEvenGrandparent(TreeNode* root) {
    if(!root) return 0;
    int ans = 0;
    solve(ans, false, false, root);
    return ans;
    }
};
