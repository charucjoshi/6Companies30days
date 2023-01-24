class Solution {
public:
    bool is_valid(vector<vector<int>> &grid, vector<vector<int>> &vis, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return false;
        if(vis[i][j] == 1 || grid[i][j] == 1) return false;

        return true;
    }
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int i, int j){
        vis[i][j] = 1;
        grid[i][j] = 1;
        if(is_valid(grid,vis,i-1,j))
            dfs(grid,vis,i-1,j);
        if(is_valid(grid,vis,i,j+1))
            dfs(grid,vis,i,j+1);
        if(is_valid(grid,vis,i+1,j))
            dfs(grid,vis,i+1,j);
        if(is_valid(grid,vis,i,j-1))
            dfs(grid,vis,i,j-1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i = 0; i < m; ++i){
            if(vis[i][0] == 0 && grid[i][0] == 0)
                dfs(grid,vis,i,0);
            if(vis[i][n-1] == 0 && grid[i][n-1] == 0)
                dfs(grid,vis,i,n-1);
        }
        for(int i = 0; i < n; ++i){
            if(vis[0][i] == 0 && grid[0][i] == 0)
                dfs(grid,vis,0,i);
            if(vis[m-1][i] == 0 && grid[m-1][i] == 0)
                dfs(grid,vis,m-1,i);
        }

        for(int i = 1; i < m-1; ++i)
            for(int j = 1; j < n-1; ++j){
                if(vis[i][j] == 0 && grid[i][j] == 0)
                {
                    ans++;
                    dfs(grid,vis,i,j);
                }
            }
        return ans;
    }
};