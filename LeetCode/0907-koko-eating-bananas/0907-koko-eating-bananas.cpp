class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        //if n==h return max of piles;
        int maxN=0;
        for(int i=0;i<n;i++){
            maxN=max(maxN,piles[i]);
        }
        if(n==h){
        return maxN;
        }

        int l=1;
        int r=maxN;
        int j=0;
        while(l<=r ){
            int mid=l+(r-l)/2;
            long long hours = 0;
            for(int j=0;j<n;j++){
                hours += (piles[j] + mid - 1) / mid;
            }

            if(hours <= h){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};