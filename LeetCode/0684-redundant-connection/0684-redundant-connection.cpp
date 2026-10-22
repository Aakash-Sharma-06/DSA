class Solution {
public:
    vector<int> par;
    vector<int> rank;

    void unionByRank(int a,int b){
        int parA=find(a);
        int parB=find(b);

        if(parA==parB) return;

        if(rank[parA]==rank[parB]){
            par[parB]=parA;
            rank[parA]++;
        }
        else if(rank[parA] > rank[parB]){
            par[parB]=parA;
        }else{
            par[parA]=parB;
        }
    }

    int find(int x){
        if(par[x]==x){
            return x;
        }

        return par[x]= find(par[x]);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        par.resize(n + 1);
        rank.resize(n + 1, 0);

        for(int i=1;i<n+1;i++){
            par[i] = i;
        }

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            if(find(u)==find(v)){
                return edge;
            }
            else{
                unionByRank(u,v);
            }
        }
        return {};
    }
};