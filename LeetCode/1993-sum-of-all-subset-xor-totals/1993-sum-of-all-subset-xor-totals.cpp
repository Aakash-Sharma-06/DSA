class Solution {
public:

    int subsetUtil(vector<int>& nums,int i,int currXor){
        if(i==nums.size()){
            return currXor;
        }

        
        int include=subsetUtil(nums,i+1,currXor^nums[i]);

        int exclude=subsetUtil(nums,i+1,currXor);

        return include+exclude;

    }

    int subsetXORSum(vector<int>& nums) {
        return subsetUtil(nums,0,0);
    }
};