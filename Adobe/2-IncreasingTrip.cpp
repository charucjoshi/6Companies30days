class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 3) return false;
        vector<int> pref(n), suff(n);
        pref[0] = nums[0];
        for(int i = 1; i < n; ++i){
            if(nums[i] < pref[i-1])
                pref[i] = nums[i];
            else
                pref[i] = pref[i-1];
        }

        suff[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; --i)
            if(nums[i] > suff[i+1])
                suff[i] = nums[i];
            else
                suff[i] = suff[i+1];
        
        for(int i = 1; i < n-1; ++i)
            if(pref[i-1] < nums[i] && nums[i] < suff[i+1])
                return true;
        return false;
        
    }
};