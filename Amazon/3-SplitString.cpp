class Solution {
public:
    int ans;
    void helper(int ind, string str, unordered_set<string> &s, int size){
        if(ind >= str.size())
        {
            ans = max(ans,size);
            return;
        }

        for(int l = 1; l+ind <= str.size(); ++l){
            if(s.find(str.substr(ind,l)) == s.end())
            {
                s.insert(str.substr(ind,l));
                helper(ind+l,str,s,size+1);
                s.erase(str.substr(ind,l));
            }
        }
    }
    int maxUniqueSplit(string s) {
        ans = INT_MIN;
        unordered_set<string> Set;
        helper(0,s,Set,0);
        for(auto i : Set)
            cout << i << " ";
        return ans;
    }
};