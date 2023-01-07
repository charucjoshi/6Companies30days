class Solution {
public:
    double slope(pair<int,int> a, pair<int,int> b){
        double dy = b.second - a.second;
        double dx = b.first - a.first;
        if(dx == 0)
            return DBL_MAX;
        else
            return dy/dx;
    }
    int maxPoints(vector<vector<int>>& points) {
        vector<pair<int,int>> v;
        for(auto i : points){
            v.push_back({i[0],i[1]});
        }
        sort(v.begin(),v.end());
        int n = v.size();
       
        if(v.size() == 1)
            return 1;
        vector<map<double,int>> slp(n);
        for(int i =0; i < n; ++i)
        {
            map<double,int> m;
            for(int j = 0; j < n; ++j){
                if(i == j) continue;  
                double s = slope(v[i],v[j]);
                m[s]++;
            }
            slp[i] = m;
        }
        int ans = INT_MIN;
        for(auto i : slp)
        {
            for(auto j : i)
                ans = max(ans,j.second);
        }
    return ans+1;
    }
};