class Solution {
public:

    void subset(vector<int>& candidates,vector<vector<int>>& ans,vector<int>& ds, int target,int sum,int i){
        int n=candidates.size();
        if(sum==target){
            ans.push_back(ds);
            return;
        }
        if(i==n || sum > target){
            return;
        }

       for(int j=i ;j<n;j++){
        if(j>i && candidates[j] == candidates[j-1]){
            continue;
        }
        if (sum + candidates[j] > target) {
                break;
            }

         ds.push_back(candidates[j]);

        subset(candidates, ans, ds, target,sum + candidates[j], j + 1);
        ds.pop_back();
       }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        subset(candidates,ans,ds,target,0,0);
        return ans;
    }
};