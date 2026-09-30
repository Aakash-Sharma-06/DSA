class Solution {
public:

    bool isPossible(vector<int>& nums,vector<int>& arr,int idx,int target,int k){
        
        if(idx==nums.size()){
            return true;
        }

        for(int i=0;i<k;i++){
            
            if(arr[i] + nums[idx] > target) continue;

            if(i>0 && arr[i]==arr[i-1]) continue;

            arr[i]+=nums[idx];
            if(isPossible(nums,arr,idx+1,target,k)){
                return true;
            }
            arr[i]-=nums[idx];
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        vector<int> arr(k,0);

        int total=0;

        for(int n:nums){
            total+=n;
        }
        if(total % k !=0) return false;

        sort(nums.rbegin(),nums.rend());
        
        int target=total/k;

        if(nums[0] > target)
            return false;


        return isPossible(nums,arr,0,target,k);
    }
};