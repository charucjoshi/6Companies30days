class Solution {
public:
    bool bound_check(int a, int b, int n){
        if(a >= 0 && a < n && b >= 0 && b < n)
            return true;
        else return false;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> curr(n,vector<double>(n,0));
        vector<vector<double>> next(n,vector<double>(n,0));
        curr[row][column] = 1.0;
        for(int m = 1; m <= k; ++m){
            for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    int ni, nj;

                    ni = i - 2;
                    nj = j - 1;
                    if(bound_check(ni,nj,n))
                    {
                        next[ni][nj] += curr[i][j]/8;
                    }
                    ni = i - 2;
                    nj = j + 1;
                    if(bound_check(ni,nj,n))
                    {
                        next[ni][nj] += curr[i][j]/8;
                    }
                    
                    ni = i - 1;
                    nj = j + 2;
                    if(bound_check(ni,nj,n))
                    {
                        next[ni][nj] += curr[i][j]/8;
                    }
                    
                    ni = i + 1;
                    nj = j + 2;
                    if(bound_check(ni,nj,n))
                    {
                        next[ni][nj] += curr[i][j]/8;
                    }
                    
                    ni = i + 2;
                    nj = j + 1;
                    if(bound_check(ni,nj,n))
                    {
                        next[ni][nj] += curr[i][j]/8;
                    }
                    
                    ni = i + 2;
                    nj = j - 1;
                    if(bound_check(ni,nj,n))
                    {
                        next[ni][nj] += curr[i][j]/8;
                    }
                    
                    ni = i - 1;
                    nj = j - 2;
                    if(bound_check(ni,nj,n))
                    {
                        next[ni][nj] += curr[i][j]/8;
                    }
                    
                    ni = i + 1;
                    nj = j - 2;
                    if(bound_check(ni,nj,n))
                    {
                        next[ni][nj] += curr[i][j]/8;
                    }
                }
            }
            curr.swap(next);
            next = vector<vector<double>>(n,vector<double>(n,0));
        }
        double ans = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                ans += curr[i][j];
        return ans;
    }
};