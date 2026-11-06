class Solution {
public:

    vector<int> toposort(vector<vector<int>>& adj, int k) {
        vector<int> result;
        vector<int> indegree(k + 1, 0);

        for (int i = 1; i <= k; i++) {
            for (int v : adj[i]) {
                indegree[v]++;
            }
        }

        queue<int> q;

        for (int i = 1; i <= k; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            result.push_back(curr);

            for (int v : adj[curr]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (result.size() != k) {
            return {};
        }

        return result;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {

        vector<vector<int>> result(k, vector<int>(k, 0));
        vector<vector<int>> adj1(k + 1);
        vector<vector<int>> adj2(k + 1);

        for (int i = 0; i < rowConditions.size(); i++) {
            int u = rowConditions[i][0];
            int v = rowConditions[i][1];
            adj1[u].push_back(v);
        }

        for (int i = 0; i < colConditions.size(); i++) {
            int u = colConditions[i][0];
            int v = colConditions[i][1];
            adj2[u].push_back(v);
        }

        vector<int> row = toposort(adj1, k);
        vector<int> col = toposort(adj2, k);

        if (row.empty() || col.empty()) {
            return {};
        }

        vector<int> rowPos(k + 1);
        vector<int> colPos(k + 1);

        for (int i = 0; i < k; i++) {
            rowPos[row[i]] = i;
            colPos[col[i]] = i;
        }

        for (int i = 1; i <= k; i++) {
            result[rowPos[i]][colPos[i]] = i;
        }

        return result;
    }
};