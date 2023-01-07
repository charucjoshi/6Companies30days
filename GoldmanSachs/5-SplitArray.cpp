class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> am, vm;
        int n = nums.size();
        for(int i = 0; i < n; ++i)
            am[nums[i]]++;
        
        for(int i = 0; i < n; ++i){
            if(am[nums[i]] <= 0) continue;

            else if(vm[nums[i]] > 0)
            {
                vm[nums[i]]--;
                am[nums[i]]--;
                vm[nums[i]+1]++;
            }
            else if(am[nums[i]] > 0 && am[nums[i]+1] > 0 && am[nums[i]+2] > 0)
            {
                am[nums[i]]--;
                am[nums[i]+1]--;
                am[nums[i]+2]--;
                vm[nums[i]+3]++;
            }
            else
                return false;
        }
        return true;
    }
};