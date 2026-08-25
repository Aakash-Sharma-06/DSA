class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for(vector<int> n:points){
            int dist = n[0] * n[0] + n[1] * n[1];
            pq.push({dist,n});

            if(pq.size()>k){
                pq.pop(); 
            }
        }
        vector<vector<int>> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};