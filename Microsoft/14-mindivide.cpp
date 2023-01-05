class Solution {
public:
    int hcf(int a, int b){
        if(a%b == 0)
            return b;
        else
        return hcf(b,a%b);
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int one = numsDivide[0];
        for(int i = 1; i < numsDivide.size(); ++i)
            one = hcf(numsDivide[i],one);
     
        sort(nums.begin(),nums.end());
        
        int ans = 0;
        bool flag = true;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > one)
                break;
            else
            {
                if(one % nums[i] == 0)
                {
                    flag = false;
                    break;
                }
                else
                {
                    ans++;
                }
            }
        }
        if(flag)
            return -1;
        return ans;
    }
};