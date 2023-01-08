class Solution {
public:
    long long int mod = (long long int)1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        map<long long int,long long int> isDelay;
        map<long long int,long long int> isForget;
        vector<long long int> dp(n);
        long long int gone = 0;
        dp[0] = 1;
        isDelay[0+delay]++;
        isForget[0+forget]++;
        long long int allowed = 0;
        for(long long int i = 1; i < n; ++i){
            if(isDelay[i]>0)
            {
                allowed = (allowed+ isDelay[i])%mod;
            }
            if(isForget[i]>0)
            {
                allowed = (allowed - isForget[i] + mod)%mod;
                gone = isForget[i]%mod;
            }
            dp[i] = (dp[i-1] + allowed - gone + mod)%mod;
            if(dp[i] != dp[i-1] || gone)
            {
                
                isForget[i+forget] = (isForget[i+forget] + allowed)%mod;
                isDelay[i+delay] = (isDelay[i+delay] + allowed)%mod;
            }
            gone = 0;
        }        
        return dp[n-1]%mod;
    }
};