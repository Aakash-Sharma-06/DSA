/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int sum(TreeNode* root,int &ans){
        if(root==nullptr) return 0;
        int l=max(sum(root->left,ans),0);
        int r=max(sum(root->right,ans),0);

        int new_price=root->val+l+r;

        ans=max(ans,new_price);
        return root->val+max(l,r);
    }

    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        sum(root,ans);
        return ans;
    }
};