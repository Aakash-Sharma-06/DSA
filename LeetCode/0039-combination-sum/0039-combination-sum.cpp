class Solution {
public:

    void subset(vector<int>& candidates,vector<int>& ds,vector<vector<int>>& ans,int sum, int target,int i){
        int n=candidates.size();
        if(sum==target){
            ans.push_back(ds);
            return;
        }
        if(i==n || sum > target){
            return;
        }
        ds.push_back(candidates[i]);
        subset(candidates,ds,ans,sum+candidates[i],target,i);

        ds.pop_back();
        subset(candidates,ds,ans,sum,target,i+1);        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        int sum=0;
        vector<vector<int>> ans;
        subset(candidates,ds,ans,sum,target,0);
        return ans;
    }
};