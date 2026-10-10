class Solution {
public:

class graph{
    int V;
    list<int> *l;

    public:
    graph(int V){
        this->V=V;
        l= new list<int>[V+1];
    }
   
        void addEdge(vector<int>& v) {
            int a = v[0];
            int b = v[1];

            l[a].push_back(b);
        }

        int judge(){
        vector<int> indegree(V+1,0);
        vector<int> outdegree(V+1,0);

        for(int i=1;i<=V;i++){
            for( int node: l[i]){
                outdegree[i]++;
                indegree[node]++;
            }
        }

        for(int j=1;j<=V;j++){
            if(indegree[j]== V-1 && outdegree[j]==0){
                return j;
            }
        }
        return -1;
    }
    
};

 
    int findJudge(int n, vector<vector<int>>& trust) {
        graph g(n);

        for(int i=0;i<trust.size();i++){
            g.addEdge(trust[i]);
        }

        return g.judge();
    }
};