class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> changes(1001, 0);

        for(auto trip : trips){
            int passenger = trip[0];
            int from = trip[1];
            int to = trip[2];

            changes[from]+= passenger;
            changes[to]-= passenger;
        }
        int total=0;
        
         for(int i=0;i<1001;i++){
            total+=changes[i];

            if(total>capacity){
                return false;
            }
         }

    return true;
    }
};