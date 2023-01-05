class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int f0 = 0;
        int sum = 0;
        for(int i = 0; i < n; ++i)
        {
            f0 += nums[i]*i;
            sum += nums[i];
        }

        int dp[n];
        dp[0] = f0;
        for(int i =1; i < n; ++i){
            dp[i] = dp[i-1] + sum - n*nums[n-i];
        }
        int ans = INT_MIN;
        for(int i = 0; i < n; ++i)
            ans = max(ans,dp[i]);
        return ans;
    }
};