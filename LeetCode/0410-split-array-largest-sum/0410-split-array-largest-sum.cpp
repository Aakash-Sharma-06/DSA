class Solution {
public:

    bool canSplit(vector<int> nums,int k,int limit){
            int parts=1;
            int sum=0;

            for(int x:nums){
                if(sum+x<=limit){
                    sum+=x;
                }
                else{
                    parts++;
                    sum=x;
                }
            }
            return parts<=k;
        }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);

        while(low<=high){
            int mid=low+(high-low)/2;

            if(canSplit(nums,k,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};