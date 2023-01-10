class Solution {
public:
    long long int mod = 1e9+7;
    
    long long int rev(int a){
        long long int r = 0;
        while(a!= 0)
        {
            r*= 10;
            r += a%10;
            a/=10;
        }
        return r;
    }
    long long int fact(long long int n){
        
        return n*(n-1);
    }
    long long int choose(int n){
        return (fact(n)/2);
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        map<long long int,int> m;
        for(int i = 0; i < n; ++i){
            m[(nums[i] - rev(nums[i]))]++;
        }
        cout << endl;
        int ans = 0;
        for(auto i : m){
            cout << i.second << " "<<choose(i.second) << endl;
            if(i.second >=2)
                ans = (ans + choose(i.second))%mod;
        }
        return ans%mod;
    }
};