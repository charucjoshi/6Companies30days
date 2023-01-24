class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int n = special.size();
        sort(special.begin(),special.end());
        int ans;
        if(special[0] == bottom)
            ans = 0;
        else
            ans = special[0]-bottom;
        bottom = special[0];
        for(int i = 1; i < n; ++i)
        {
            ans = max(ans,special[i]-bottom-1);
            bottom = special[i];
        }
        ans = max(ans,top-bottom);
        return ans;
    }
};