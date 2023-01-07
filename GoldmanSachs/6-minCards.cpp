class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        vector<pair<int,int>> v;
        for(int i = 0; i < cards.size(); ++i){
            v.push_back({cards[i],i});
        }
        sort(v.begin(),v.end());
        int ans = INT_MAX;
        for(int i = 0; i < v.size()-1; ++i){
            if(v[i].first == v[i+1].first)
                ans = min(ans,v[i+1].second-v[i].second+1);
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};