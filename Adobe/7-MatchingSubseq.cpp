class Solution {
public:
    bool lcs(string w, string s){
        int n = s.length();
        int m = w.length();
        int mi = 0;
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == w[mi])
                mi++;
            if(mi == m)
                return true;
        }
        
        return false;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        map<string, int> m;
        for(int i = 0; i < words.size(); ++i)
        {
            if(m[words[i]] == 1) ans++;
            else if(m[words[i]] == -1) continue;
            else
            {
                if(lcs(words[i], s)){
                    m[words[i]] = 1;
                    ans++;
                }
                else m[words[i]] = -1;
            }
        }
        return ans;
    }
};