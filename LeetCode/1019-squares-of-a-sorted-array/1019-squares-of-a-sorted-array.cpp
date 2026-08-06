class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int l=0;
        int r=n-1;
        int pos = n - 1;

        while(l<=r){
            int numl=nums[l];
            int numr=nums[r];
            if(abs(numl)>abs(numr)){
                ans[pos] = numl * numl;
                l++;
            }
            else{
                ans[pos] = numr * numr;
                r--;
            }
            pos--;
        }


        return ans;
    }
    
};