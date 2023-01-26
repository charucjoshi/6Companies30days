class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();  
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int ru, rl, cu, cl;
                ru = i + k;
                if(ru >= m) ru = m-1;
                rl = i-k;
                if(rl < 0) rl = 0;
                cu = j+k;
                if(cu >= n) cu = n-1;
                cl = j-k;
                if(cl < 0) cl = 0;
                int sum = 0;
                for(int ri = rl; ri <= ru; ++ri)
                    for(int cj = cl; cj <= cu; ++cj)
                        sum += mat[ri][cj];
                ans[i][j] = sum;
            }
        }
        return ans;
    }
};