class Solution {
public:

    void combineUtil(int i,int n,int k,vector<vector<int>>& ans,vector<int>& ds){
        if(ds.size()==k){
            ans.push_back(ds);
            return;
        }
        if(i>n) return;

        int j=i;
        int count=k;
        
        ds.push_back(i);
        combineUtil(i+1,n,k,ans,ds);

        ds.pop_back();
        combineUtil(i+1,n,k,ans,ds);

        // combineUtil(i+1,n,k,ans,ds);
        
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
       
        combineUtil(1,n,k,ans,ds);
        return ans;
    }
};