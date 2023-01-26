class Solution {
public:
    int distinctEchoSubstrings(string text) {
        set<string> s;
        int n = text.length();
        for(int len = 1; len <= n; ++len){
            int count = 0;
            for(int l = 0, r = len; r < n; ++l,++r)
            {
                if(text[l] == text[r])
                    count++;
                else
                    count = 0;
                
                if(count == len)
                {
                    count--;
                    s.insert(text.substr(l,r-l+1));
                }
            }
        }
        return s.size();
    }
};