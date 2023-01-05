class Solution {
public:
    string longestPrefix(string s) {
        // KMP - KNUTH-MORRIS-PRATT
        int n = s.length();
        vector<int> lsp(n,0);
        int i = 1, len = 0;
        while(i < n){
            if(s[i] == s[len])
            {
                len++;
                lsp[i] = len;
                i++;
            }
            else if(len > 0)
                len = lsp[len-1];
            else
            {
                lsp[i] = 0;
                i++;
            }
        }

        return s.substr(n-lsp[n-1]);
    }
};