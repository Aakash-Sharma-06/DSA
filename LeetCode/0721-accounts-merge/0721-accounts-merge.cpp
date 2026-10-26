class DisjointSetUnion {
public:
    int n;
    vector<int> par, rank;

    DisjointSetUnion(int n) {
        this->n = n;

        for (int i = 0; i < n; i++) {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        }

        return par[x] = find(par[x]);
    }

    void unionbyRank(int a, int b) {
        int parA = find(a);
        int parB = find(b);

        if (parA == parB) return;

        if (rank[parA] == rank[parB]) {
            par[parB] = parA;
            rank[parA]++;
        }
        else if (rank[parA] > rank[parB]) {
            par[parB] = parA;
        }
        else {
            par[parA] = parB;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        DisjointSetUnion ds(n);
        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];

                if (mp.find(mail) == mp.end()) {
                    mp[mail] = i;
                }
                else {
                    ds.unionbyRank(i, mp[mail]);
                }
            }
        }

        vector<vector<string>> merge(n);

        for (auto &it : mp) {
            string mail = it.first;
            int node = ds.find(it.second);

            merge[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (merge[i].size() == 0) continue;

            sort(merge[i].begin(), merge[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for (auto it : merge[i]) {
                temp.push_back(it);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
