class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int stone : stones) {
            pq.push(stone);
        }
        while (pq.size() > 1){
            
        int num1=pq.top();
        pq.pop();
        int num2=pq.top();
        pq.pop();
        int res=num1-num2;
        if(res>0){
            pq.push(res);
        }
        else{
            continue;
        }
        }
        
        if(pq.size()>0){
            return pq.top();
        }
        return 0;
    }
};