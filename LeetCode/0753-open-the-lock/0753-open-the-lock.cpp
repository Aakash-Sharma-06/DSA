class Solution {
public:


    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        string s="0000";

        unordered_set<string> dead(deadends.begin(),deadends.end());
        unordered_set<string> vis;

        if(dead.count(s)) return -1;
        q.push(s);
        
        vis.insert(s);

        int steps = 0;

        while(!q.empty()){
            int size=q.size();

            for (int j = 0; j < size; j++) {
                string curr = q.front();
                q.pop();

                if (curr == target) return steps;

                for (int i = 0; i < 4; i++) {
                    int digit = curr[i] - '0';

                    string next=curr;
                    next[i]='0'+ (digit+1)%10;

                    if(!dead.count(next) && !vis.count(next)){
                        q.push(next);
                        vis.insert(next);
                    }

                    next=curr;
                    next[i]='0'+ (digit+9)%10;

                    if(!dead.count(next) && !vis.count(next)){
                        q.push(next);
                        vis.insert(next);
                    }
                  
                }
            }

            steps++;
        }

        return -1;
    }
};