class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(int n:nums){
            pq.push(n);
        }
        if(k==0) return pq.top();
        while(k-1>0){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};