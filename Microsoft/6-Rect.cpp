class Solution {
public:
    long long int area(pair<int,int> a, pair<int,int> b){
        long long int l = b.first - a.first;
        long long int w = b.second - a.second;
        long long int ans = l*w;
        return ans; 
    }
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        vector<pair<pair<int,int>,pair<int,int>>> v;
        for(auto i : rectangles){
            v.push_back({{i[0],i[1]},{i[2],i[3]}});
        }
        long long int sum = 0;
        pair<int,int> f = {INT_MAX,INT_MAX}, l = {INT_MIN,INT_MIN};
        map<pair<int,int>, int> m;
        for(int i = 0; i < n; ++i){
            
            if(m[v[i].first])
                m.erase(v[i].first);
            else m[v[i].first]++;
            if(m[v[i].second])
                m.erase(v[i].second);
            else
                m[v[i].second]++;
            if(m[{v[i].first.first, v[i].second.second}])
                m.erase({v[i].first.first, v[i].second.second});
            else
                m[{v[i].first.first, v[i].second.second}]++;
            if(m[{v[i].second.first,v[i].first.second}])
                m.erase({v[i].second.first,v[i].first.second});
            else
                m[{v[i].second.first,v[i].first.second}]++;

            sum += area(v[i].first, v[i].second);
            if(v[i].first.first < f.first){
                f.first = v[i].first.first;
                f.second = v[i].first.second;
            }
            else if(v[i].first.first == f.first){
                if(v[i].first.second < f.second)
                    f.second = v[i].first.second;
            }
            if(v[i].second.first > l.first){
                l.first = v[i].second.first;
                l.second = v[i].second.second;
            }
            else if(v[i].second.first == l.first){
                if(v[i].second.second > l.second)
                    l.second = v[i].second.second;
            }
        }
        bool flag = false;
        if(m[f]==1 && m[l]==1 && m[{f.first,l.second}]==1 && m[{l.first,f.second}]==1 && m.size() == 4) flag = true;

        cout << sum << endl;
        cout << area(f,l) << endl;
        if(sum == area(f,l)&& flag)
        return true;
        return false;
    }
};