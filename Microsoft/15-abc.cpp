class Solution {
public:
    int numberOfSubstrings(string s) {
        int ia, ib, ic;
        ia = ib= ic = -1;
        int ans = 0;
        for(int i = 0; i < s.length(); ++i)
        {
            if(s[i] == 'a') ia = i;
            if(s[i] == 'b') ib = i;
            if(s[i] == 'c') ic = i;
            if(i > 1)
            ans += min(ia,min(ib,ic)) + 1;
        }

        return ans;
    }
};