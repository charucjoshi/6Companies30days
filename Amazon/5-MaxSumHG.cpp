class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>>& grid)
    {
        int m = grid.size(); int n = grid[0].size();
        if(i+2 < m && j+2 < n) return true;
        return false;
    }
    int sumHourGlass(int i, int j, vector<vector<int>>& grid){
        int sum = 0;
        sum = grid[i][j] + grid[i][j+1] + grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j]
                + grid[i+2][j+1]+grid[i+2][j+2];
        return sum;
    }
    int maxSum(vector<vector<int>>& grid) {
        int ans = INT_MIN;
        int m = grid.size(); int n = grid[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(isValid(i,j,grid))
                {
                    int sum = sumHourGlass(i,j,grid);
                    ans = max(sum,ans);
                }
            }
        }
        return ans;   
    }
};