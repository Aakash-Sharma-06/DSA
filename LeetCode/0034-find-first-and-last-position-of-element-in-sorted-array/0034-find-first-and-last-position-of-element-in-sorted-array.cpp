class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        int first = -1;
        int last = -1;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(nums[mid]==target){
                
                if(mid==0 || nums[mid-1]!=target){
                    first=mid;
                    break;
                }
                else{
                    r=mid-1;
                }      
            }

            else if(nums[mid]<target){
                l=mid+1;
            }else{
                r=mid-1;
            }

        }
        l = 0;
        r = n - 1;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(nums[mid]==target){

                if(mid==n-1 || nums[mid+1]!=target){
                  last=mid;
                  break;
                }
                else{
                    l=mid+1;
                }       
            }

            else if(nums[mid]<target){
                l=mid+1;
            }else{
                r=mid-1;
            }

        }
            return {first,last};
    }
};