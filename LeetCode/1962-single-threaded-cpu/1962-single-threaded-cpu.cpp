class Solution {
public:

    struct Task {
        int enqueueTime;
        int processingTime;
        int index;
    };

    vector<int> getOrder(vector<vector<int>>& tasks) {

        int n = tasks.size();
        vector<Task> v;

        for(int i=0;i<n;i++){
             v.push_back({tasks[i][0],
                        tasks[i][1],  
                        i
                        });
        }

        sort(v.begin(), v.end(), [](Task a, Task b) {
            return a.enqueueTime < b.enqueueTime;
        });

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> ans;

        long long time = 0;
        int i = 0;

        while(i<n || !pq.empty()){
            
            if(pq.empty()){
                time=max(time,(long long)v[i].enqueueTime);
            }

            while(i < n && v[i].enqueueTime<=time){
                pq.push({
                    v[i].processingTime,
                    v[i].index
                });

                i++;
            }

            int processingTime=pq.top().first;
            int index=pq.top().second;

            pq.pop();

            ans.push_back(index);

            time+= processingTime;
        }
        return ans;   
    }
};