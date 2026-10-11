class Solution {
public:
class graph{
    public:
    int V;
    list<int> *l;

    graph(int V){
        this->V=V;
        l= new list<int>[V];
    }

    void addEdge(vector<int> n){
        int a=n[0];
        int b=n[1];

        l[b].push_back(a);
    }

    bool isCycle(int u,vector<bool>& vis,vector<bool>& recPath){
        vis[u]=true;
        recPath[u]=true;

        for(int v: l[u]){
            if(!vis[v]){
                if(isCycle(v,vis,recPath)){
                    return true;
                }
                }else if(recPath[v]){
                    return true;
                }
            }
            recPath[u]=false;
            return false;
    }

    void topoSort(int u,vector<bool>& vis1,stack<int>& st){
        vis1[u]=true;

        for(int v:l[u]){
            if(!vis1[v]){
                topoSort(v,vis1,st);
            }
        }
        st.push(u);
    }
    
};

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<bool> vis(n,false);
        vector<bool> recPath(n,false);

        graph g(n);

        for(int i=0;i<prerequisites.size();i++){
            g.addEdge(prerequisites[i]);
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(g.isCycle(i,vis,recPath)){
                    return {};
                }
            }
        }
        vector<bool> vis1(n,false);      
        stack<int> st;
        for(int i=0;i<n;i++){
            if(!vis1[i]){
                g.topoSort(i,vis1,st);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};