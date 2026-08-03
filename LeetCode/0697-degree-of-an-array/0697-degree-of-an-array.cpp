class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> freq,first,last;
    
        int n=nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]++;

            if(first.find(nums[i]) == first.end()){
                first[nums[i]]=i;
            }

            last[nums[i]]=i;
        }

        int degree=0;
        for(auto &p:freq){
            degree=max(degree,p.second);
        }
        int ans=nums.size();
        for(auto &p:freq){
            if(p.second==degree){
                ans=min(ans,last[p.first]-first[p.first]+1);
            }
        }
        return ans;
    }
};