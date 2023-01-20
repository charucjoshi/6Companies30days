class Solution {
public:
    static bool compare(pair<int,string> &a, pair<int,string> &b){
        if(a.first > b.first) return true;
        else if(a.first == b.first){
            if(a.second < b.second) return true;
        }
        return false;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        for(auto i : words){
            m[i]++;
        }
        vector<pair<int, string>> v;
        vector<string> ans;

        for(auto i : m)
            v.push_back({i.second,i.first});
        sort(v.begin(),v.end(),compare);
        for(int i = 0; i < k; ++i)
            ans.push_back(v[i].second);
        return ans;
    }
};