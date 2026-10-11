class Solution {
public:

    class graph{
        public:
        int V;
        list<int> *l;

        graph(int V){
            this->V=V;
            l=new list<int>[V];
        }

        void addEdge(vector<int> v){
            int a=v[0];
            int b=v[1];

            l[b].push_back(a);
        }

        bool isCycle(int src,vector<bool>& vis,vector<bool>& recpath){
            vis[src]=true;
            recpath[src]=true;

            for(int v:l[src]){
                if(!vis[v]){
                    if(isCycle(v,vis,recpath)){
                        return true;
                    }
                }else if(recpath[v]){
                    return true;
                }
            }
            recpath[src]=false;
            return false;
        }
    };

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;

        graph g(n);

        vector<bool> vis(n,false);
        vector<bool> recpath(n,false);

        for(int i=0;i<prerequisites.size();i++){
            g.addEdge(prerequisites[i]);
        }

        for(int i=0;i<n;i++){
            if (!vis[i]) {
                if (g.isCycle(i, vis, recpath)) {
                    return false;
                }
            }
        }

        return true;
    }
};