class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int mv=0;
        for(int i=0;i<n;i++){
            mv=max(mv,nums[i]);
        }
        int count=0;
        for(int x:nums){
            while(x<mv){
                x++;
                count++;
            }
        }
        return count;
    }
};