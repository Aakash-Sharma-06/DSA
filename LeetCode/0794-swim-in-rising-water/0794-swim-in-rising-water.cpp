class Solution {
public:
    vector<vector<int>> dir = {
        {-1, 0}, // Up
        {1, 0},  // Down
        {0, -1}, // Left
        {0, 1}   // Right
    };

    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int n,int t, int i, int j) {
        if (i == n - 1 && j == n - 1) {
            return true;
        }

        if (vis[i][j]) {
            return false;
        }

        vis[i][j] = true;

        for (auto d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];
            if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                if(!vis[ni][nj] && grid[ni][nj] <= t) {
                    if (dfs(grid, vis, n, t, ni, nj)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        int t = 0;

        int low = max(grid[0][0], grid[n-1][n-1]);
        int high=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                high=max(high,grid[i][j]);
            }
        }

        while(low<high){
            int mid=low+ (high-low)/2;
            vector<vector<bool>> vis(n, vector<bool>(n, false));

            if( dfs(grid, vis, n, mid, 0, 0)){
                high=mid;
            }
            else {
                low = mid + 1;
            }   
        }

        return low;
    }
};