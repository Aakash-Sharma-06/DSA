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

    void helper(TreeNode* root,int& count, int maxVal){
        if(root==nullptr) return;

        if(root->val>=maxVal){
            count++;
            maxVal=root->val;
        }
        helper(root->left,count,maxVal);
        helper(root->right,count,maxVal);

    }

    int goodNodes(TreeNode* root) {
        int count=0;
        if(!root) return count;
        helper(root,count,root->val);

        return count;
    }
};