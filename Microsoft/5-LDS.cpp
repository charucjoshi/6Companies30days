class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // sort the array
        sort(nums.begin(),nums.end());
        int n = nums.size();
        // similar to lis : I finding hash
        vector<int> dp(n,1), hash(n,0);
        int lastInd = 0, maxi = 1;
        for(int i = 1; i < n; ++i)
        {
            hash[i] = i;
            for(int j = 0; j < i; ++j){
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = 1+ dp[j];
                    hash[i] = j;
                }
                if(dp[i] > maxi)
                {
                    maxi = dp[i];
                    lastInd = i;
                }
            }
        }

        vector<int> seq;
        seq.push_back(nums[lastInd]);
        while(hash[lastInd] != lastInd)
        {
            lastInd = hash[lastInd];
            seq.push_back(nums[lastInd]);
        }
        reverse(seq.begin(),seq.end());
        return seq;    
    }
};