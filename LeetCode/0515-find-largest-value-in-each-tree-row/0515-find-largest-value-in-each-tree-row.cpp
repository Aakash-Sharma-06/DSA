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

    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> level;

            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                level.push_back(node->val);
            

            if(node->left!=nullptr){
                q.push(node->left);
            }
            if(node->right!=nullptr){
                q.push(node->right);
            }
            }
            ans.push_back(level);
        }
        return ans;
    }

    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>> v;
        v=levelOrder(root);
        vector<int> result;
         for (const auto& row : v) {
            if (!row.empty()) {
                int maxVal = *std::max_element(row.begin(), row.end());
                result.push_back(maxVal);
        }
    }
    return result;
    }
};