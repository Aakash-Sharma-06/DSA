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

    int levelOrder(TreeNode* root,int sum,int level){
        queue<TreeNode*> q;
        int maxLevel = 1;
        if(root == nullptr) return 0;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            int s=0;
            
           for(int i=0;i<size;i++){
            TreeNode* node= q.front(); 
            q.pop();
            s+=node->val;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
           }
           
           if(s>sum){
            sum=s;
            maxLevel=level;
           }
           level++;
        }
        return maxLevel;
    }

    int maxLevelSum(TreeNode* root) {
        
        int ans=levelOrder(root,INT_MIN,1);
        return ans;
    }
};