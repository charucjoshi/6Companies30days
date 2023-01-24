class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        int t = n/3;
        int ans = 0;
        sort(piles.begin(),piles.end());
        int ind = n-2;
        while(t--)
        {
            ans += piles[ind];
            ind-=2;
        }
    return ans;
    }
};