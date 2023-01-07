class Solution {
public:
    static bool sortCond(pair<int,int> &a, pair<int,int> &b){
        if(a.first != b.first)
            return a.first < b.first;
        else
            return a.second > b.second;
    }
    int dist(pair<int,int> a, pair<int,int> b){
        int dx = abs(a.first-b.first);
        int dy = abs(a.second-b.second);

        return (dx*dx+dy*dy);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        //check all sides
        bool side = false;
        vector<pair<int,int>> v;
        v.push_back({p1[0],p1[1]});
        v.push_back({p2[0],p2[1]});
        v.push_back({p3[0],p3[1]});
        v.push_back({p4[0],p4[1]});
        
        int d1 = dist(v[0],v[1]);
        int d2 = dist(v[0],v[2]);
        int d3 = dist(v[0],v[3]);
        int d4 = dist(v[1],v[2]);
        int d5 = dist(v[1],v[3]);
        int d6 = dist(v[2],v[3]);
        if(!(d1&&d2&&d3&&d4&&d5
        &&d6)) return false;
        map<int,int> m;
        m[d1]++;
        m[d2]++;
        m[d3]++;
        m[d4]++;
        m[d5]++;
        m[d6]++;
        if(m.size()!=2) return false;
        for(auto i : m)
            if(i.second == 2 || i.second == 4)
                continue;
            else return false;
        
        return true;
    }
};