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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
          return true;
        }
        if(p==NULL || q==NULL){
          return false;
        }

        if(p->val!=q->val){
            return false;
        }
        

        bool ans_left=isSameTree(p->left,q->left);
        bool ans_right=isSameTree(p->right,q->right);

        if(ans_left && ans_right){
            return true;
        }else{
            return false;
        }
    }
};