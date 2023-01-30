class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> dp(m+1,0);
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = m-1; j >= 0; --j){
                if(nums1[i] == nums2[j])
                {
                    dp[j+1] = 1+dp[j];
                }
                else
                    dp[j+1] =0;
                ans = max(ans, dp[j+1]);
            }
           
        }
        return ans;
    }
};