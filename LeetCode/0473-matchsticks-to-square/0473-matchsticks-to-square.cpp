class Solution {
public:

    bool isSquare(vector<int>& matchsticks,vector<int>& side,int idx,int target){

        if(idx==matchsticks.size()){
            if(side[0]==side[1] && side[1]==side[2] && side[2]==side[3]){
                return true;
            }
            return false; 
        }

        for(int i=0; i< 4; i++){

            if(side[i] + matchsticks[idx]>target) continue;

            if(i>0 and side[i]==side[i-1]) continue;

            side[i] += matchsticks[idx];
            if(isSquare(matchsticks,side,idx+1,target)){
                return true;
            }
            side[i]-=matchsticks[idx];
        }
        return false;
    }


    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size()==0){
            return false;
        }

        int total = 0;

        for(int x : matchsticks)
            total += x;

        if(total % 4 != 0)
            return false;

        int target = total/4;

        sort(matchsticks.rbegin(),matchsticks.rend());
        
                    

        vector<int> side(4,0);
        return isSquare(matchsticks,side,0,target);
    }
};