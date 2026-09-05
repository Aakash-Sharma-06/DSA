class Solution {
public:

    void subset(vector<int>& nums,vector<vector<int>>& ans,vector<int>& ds,int i){
        if(i==nums.size()){
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[i]);
        subset(nums,ans,ds,i+1);

        ds.pop_back();
        int idx=i+1;
        
        while(idx<nums.size() && nums[idx]==nums[idx-1]){
            idx++;
        }

        subset(nums,ans,ds,idx);
        
    }

    

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        subset(nums,ans,ds,0);
        return ans;
    }
};