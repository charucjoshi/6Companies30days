class Solution {
public:
    bool hasAllCodes(string s, int k) {
        //Put all the substring of size 'k' in a set
        cout << s << " " << k;
        unordered_set<string> subsets;
        int n = s.length();
        for(int i = 0; i < n-k+1; ++i){
            int j = i;
            string temp="";
            while(j < k+i){
                temp += s[j];
                j++;
            }
            subsets.insert(temp);
        }
        //Check every bit(string) in the set
        int mask = 1<<k;
        for(int i = 0; i < mask; ++i){
            string temp = to_str(i,k);
            if(subsets.find(temp) == subsets.end())
                return false;
        }
        return true;
    }
    string to_str(int mask, int k){
        string ans = "";
        while(k--){
            string temp = to_string(mask&1);
            mask >>= 1;
            ans += temp;
        }
        return ans;
    }
};