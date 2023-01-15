class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int count = 0;
        long long ans = 0;
        int mini = INT_MAX;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] < 0) count++;
                matrix[i][j] = abs(matrix[i][j]);
                mini = min(matrix[i][j],mini);

                ans += matrix[i][j];
            }
        }
        if(count % 2)
            return (long long) ans - 2*mini;
        else
            return ans;
    }
};