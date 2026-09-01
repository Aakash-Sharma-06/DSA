class Solution {
public:

    void addSubset(vector<int>& nums,vector<int>& ds,vector<vector<int>>& ans,int i){
        if(i== nums.size()){
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[i]);
        addSubset(nums,ds,ans,i+1);

        ds.pop_back();
        addSubset(nums,ds,ans,i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        addSubset(nums,ds,ans,0);
        return ans;
    }
};