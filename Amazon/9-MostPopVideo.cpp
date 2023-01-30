class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string, long long int> mp;
        map<string, vector<pair<string,long long int>>> m;
        long long int ma = 0;
        long long int n = ids.size();
        for(long long int i = 0; i < n; ++i){
            mp[creators[i]] += views[i];
            ma = max(ma,mp[creators[i]]);
            m[creators[i]].push_back({ids[i],views[i]});
        }

        vector<vector<string>> ans;
        for(auto it : mp){
            if(it.second == ma){
                string id = m[it.first][0].first;
                long long int view = m[it.first][0].second;
                for(auto jt : m[it.first]){
                    if(jt.second > view){
                        view = jt.second;
                        id = jt.first;
                    }
                    else if(jt.second == view){
                        if(jt.first < id)
                            id = jt.first;
                    }
                }
                vector<string> s;
                s.push_back(it.first);
                s.push_back(id);
                ans.push_back(s);
            }
        }
        return ans;
    }
};