class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        priority_queue<pair<int,char>> pq;

        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string ans;

        while (!pq.empty()) {
            auto [f1, c1] = pq.top();
            pq.pop();

            if(ans.size()>=2 &&
                ans[ans.size()-1]==c1 &&
                ans[ans.size()-2]==c1
                ){
                    if (pq.empty())
                    break;

                    auto [f2, c2] = pq.top();
                    pq.pop(); 

                    ans += c2;
                    f2--;

                    if (f2 > 0){
                    pq.push({f2, c2});
                    }

                    pq.push({f1, c1});   
                }
                else{
                    ans+=c1;
                    f1--;

                    if (f1 > 0){
                    pq.push({f1, c1});
                    }
                }

            }
        return ans;
    }
};