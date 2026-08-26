class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto it : freq) {
            pq.push({it.second, it.first});
        }

        string ans;

        while(pq.size()>=2){
            auto[f1,c1]=pq.top();
            pq.pop();

            auto[f2,c2]=pq.top();
            pq.pop();

            ans+=c1;
            ans+=c2;

            f1--;
            f2--;

            if(f1>0){
                pq.push({f1,c1});
            }
            if(f2>0){
                pq.push({f2,c2});
            }

        }

        if(!pq.empty()){

            auto[f,c]=pq.top();

            if(f>1){
                return "";
            }

            if(!ans.empty() && ans.back()==c){
                return "";
            }

            ans+=c;
        }
        return ans;
    }
};