class Solution {
public:
    int N;
    class UnionFind {
    public:
        int V;
        vector<int> rank, par;

        UnionFind(int V) {
            this->V = V;

            for (int i = 0; i < V; i++) {
                rank.push_back(0);
                par.push_back(i);
            }
        }
        int find(int x) {
            if (par[x] == x) {
                return x;
            }

            return par[x] = find(par[x]);
        }

        void unionByRank(int a, int b) {
            int parA = find(a);
            int parB = find(b);

            if (parA == parB)
                return;

            if (rank[parA] == rank[parB]) {
                par[parB] = parA;
                rank[parA]++;
            } else if (rank[parA] > rank[parB]) {
                par[parB] = parA;
            } else {
                par[parA] = parB;
            }
        }
    };

    int kruskal(vector<vector<int>>& vec, int skip_edge, int add_edge) {
        int sum = 0;

        UnionFind uf(N);

        if (add_edge != -1) {
            uf.unionByRank(vec[add_edge][0], vec[add_edge][1]);
            sum += vec[add_edge][2];
        }

        for (int i = 0; i < vec.size(); i++) {

            if (i == skip_edge || i == add_edge) {
                continue;
            }

            int u = vec[i][0];
            int v = vec[i][1];
            int wt = vec[i][2];

            int parU = uf.find(u);
            int parV = uf.find(v);

            if (parU != parV) {
                uf.unionByRank(u, v);
                sum += wt;
            }
        }

        for (int i = 0; i < N; i++) {
            if (uf.find(i) != uf.find(0)) {
                return INT_MAX;
            }
        }

        return sum;
    }

    vector<vector<int>>
    findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N = n;

        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }

        auto lambda = [](vector<int>& vec1, vector<int>& vec2) {
            return vec1[2] < vec2[2];
        };

        sort(begin(edges), end(edges), lambda);

        int mst_weight = kruskal(edges, -1, -1);

        vector<int> critical, p_critical;

        for (int i = 0; i < edges.size(); i++) {

            if (kruskal(edges, i, -1) > mst_weight) {
                critical.push_back(edges[i][3]);
            } else if (kruskal(edges, -1, i) == mst_weight) {
                p_critical.push_back(edges[i][3]);
            }
        }

        return {critical, p_critical};
    }
};