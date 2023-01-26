class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> v;
        helper(s,0,0,"",v);
        return v;

    }
    void helper(string s, int i, int par, string ans, vector<string> &v){
        
        if(i == s.length() || par == 4){
            if(i==s.length() && par == 4)
                v.push_back(ans.substr(0,ans.length()-1));
            return;
        }
        helper(s,i+1,par+1,ans+s.substr(i,1)+".",v);
        if((i+2 <= s.length()) && isvalid(s.substr(i,2)))
            helper(s,i+2,par+1,ans+s.substr(i,2)+".",v);
        if((i+3 <= s.length()) && isvalid(s.substr(i,3)))
            helper(s,i+3,par+1,ans+s.substr(i,3)+".",v);

    }
    bool isvalid(string s){
        if(s[0] == '0') return false;
        int temp = stoi(s);

        return (temp <= 255);

    }
};