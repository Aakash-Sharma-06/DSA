class Solution {
public:
    class graph {
    public:
        int V;
        list<int>* l;

        graph(int V) {
            this->V = V;
            l = new list<int>[V];
        }

        void addEdge(vector<int> v) {
            int a = v[0];
            int b = v[1];
            l[a].push_back(b);
        }

        void dfs(int src, vector<bool>& vis) {
            vis[src] = true;

            for (int v : l[src]) {
                if (!vis[v]) {
                    dfs(v, vis);
                }
            }
        }
    };

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        int n=numCourses;
        graph g(n);

        for(int i=0;i<prerequisites.size();i++){
            g.addEdge(prerequisites[i]);
        }
        vector<bool> ans;

        vector<vector<bool>> pre(n,vector<bool>(n,false));

        for(int i=0;i<n;i++){
            vector<bool> vis(n,false);
            if(!vis[i]){
                g.dfs(i,vis);
            }

            for(int j=0;j<n;j++){
                if(i!=j && vis[j]){
                    pre[i][j] = true;
                }
            }
        }

         for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            ans.push_back(pre[u][v]);
        }

      
        return ans;
    }
};