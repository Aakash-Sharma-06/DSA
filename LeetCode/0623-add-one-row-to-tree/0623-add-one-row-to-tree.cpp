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

    void addRow(TreeNode* node, int val, int depth,int level){

        if (node == nullptr)
            return;

        if(level== depth-1){
            TreeNode* newNode1= new TreeNode(val);
            TreeNode* newNode2= new TreeNode(val);

            //save old node
            TreeNode* oldLeft =node->left;
            TreeNode* oldright =node->right;

            //current node

            node->left = newNode1;
            node->right = newNode2;

            //connect node
            newNode1->left=oldLeft;
            newNode2->right=oldright;

            return;

        }

        addRow(node->left,val,depth,level+1);
        addRow(node->right,val,depth,level+1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1){
            TreeNode* newRoot=new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }

        addRow(root,val,depth,1);

        return root;
    }
};