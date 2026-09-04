class Solution {
public:

    void permuteUtil(vector<int>& nums,vector<vector<int>>& ans,vector<int>& ds,vector<bool>& used){
        if (ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;

            else{
                used[i] = true;
                ds.push_back(nums[i]);
            }
            permuteUtil(nums,ans,ds,used);

            ds.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> used(nums.size(),false);
        permuteUtil(nums,ans,ds,used);
        return ans;
    }
};