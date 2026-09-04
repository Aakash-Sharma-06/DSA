class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
         vector<bool> used(nums.size(), false);
        findPermutation(0,nums,ds,ans,used);    
        return ans;
    }
public:
    void findPermutation(int ind,vector<int>& nums,vector<int>& ds,vector<vector<int>>& ans, vector<bool>& used){
        if(ind==nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(used[i]==true) continue;
            ds.push_back(nums[i]);
            used[i]=true;
            findPermutation(ind+1,nums,ds,ans,used);
            ds.pop_back();
            used[i]=false;
        }
    }
};
