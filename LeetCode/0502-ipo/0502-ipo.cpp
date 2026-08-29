class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> project;

        for(int i=0;i<profits.size();i++){
            project.push_back({capital[i],profits[i]});
        }

        sort(project.begin(),project.end());

        priority_queue<int> pq;

        int i=0;

        for(int j=0;j<k;j++){

            while(i<project.size() && project[i].first<=w){
                pq.push(project[i].second);
                i++;
            }

            if(pq.empty()) break;

            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};