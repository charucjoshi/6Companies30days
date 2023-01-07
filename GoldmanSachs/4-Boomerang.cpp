class Solution {
public:
    int f(int a){
	    if(a == 0 || a == 1)
		    return 1;

	    return a * f(a-1);
    }

    int c(int n){
	    return f(n)/(f(n-2)*2);
    }
    int dist(pair<int,int> a, pair<int,int> b){
	    int dx = a.first - b.first;
	    int dy = a.second - b.second;
	    return dx*dx + dy*dy;
    }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int,int>> p;
        for(int i = 0; i < n; ++i)
        {
            p.push_back({points[i][0],points[i][1]});
        }    
        
        vector<map<int,int>> distCount;

        for(int i = 0; i < n; ++i)
        {
            map<int,int> m;
            for(int j = 0; j < n; ++j)
            {
                if(i == j) continue;
                int d = dist(p[i],p[j]);
                m[d]++;
            }
            distCount.push_back(m);
        }

        int count = 0;
        for(int i = 0; i < n; ++i)
        {
            for(auto j : distCount[i])
            {
                if(j.second < 2) continue;
                count += c(j.second);
            }
        }
        return count*2;
    }
};