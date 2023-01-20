class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n+1,0);
        double res = 0;
        if(k == 0) return 1.0;
        if(k+maxPts <= n) return 1.0;
        dp[0] = 1;
        double sum = dp[0];
        for(int i = 1; i <= n; ++i){
            dp[i] = sum/(double)maxPts;

            //handle front end of window
            if(i < k){
                sum += dp[i];
            }
            else{
                res += dp[i];
            }

            //handle back end of window
            if(i - maxPts >= 0)
            {
                sum -= dp[i-maxPts];
            }
        }
        return res;
    }
};