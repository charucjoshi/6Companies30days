class Solution {
public:
    bool check(int i, int j, int n){
        if(i < 0 || j < 0 || i >= n || j >= n) return false;
        return true;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>v(n, vector<int>(n, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        pq.push({grid[0][0], {0, 0}});
        v[0][0]=grid[0][0];
        while(!pq.empty()){
            int peak=pq.top().first, r=pq.top().second.first, c=pq.top().second.second;
            pq.pop();
            int dc[4]={-1, 0, 1, 0};
            int dr[4]={0, -1, 0, 1};
            for(int i=0 ;i<4; i++){
                int row=dr[i]+r, col=dc[i]+c;
                if(check(row, col, n)){
                    if(peak<grid[row][col]){
                        v[row][col]=grid[row][col];
                        pq.push({v[row][col], {row, col}});
                    }
                    else if(peak<v[row][col]){
                        v[row][col]=peak;
                        pq.push({v[row][col], {row, col}});
                    }
                }
            }
        }
        return v[n-1][n-1];
    }
};