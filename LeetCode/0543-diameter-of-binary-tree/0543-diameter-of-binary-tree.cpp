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

    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;

        int left=maxDepth(root->left);
        int right=maxDepth(root->right);

        int ans=max(left,right)+1;
        return ans;
    }

    pair<int,int> diameter(TreeNode* root){
        if(root==nullptr){
            pair<int,int> p=make_pair(0,0);
            return p;
        }

        pair<int,int> left=diameter(root->left);
        pair<int,int> right=diameter(root->right);

        int op1=left.first;
        int op2=right.first;
        int op3=left.second+ right.second;

        pair<int,int> ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(left.second,right.second)+1;
        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).first;
    }
};