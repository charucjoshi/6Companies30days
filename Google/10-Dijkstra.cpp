class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < times.size(); ++i){
            adj[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }
        // for(int i = 0; i < n; ++i)
        // {
        //     cout << i << " -> ";
        //     for(auto j : adj[i])
        //         cout << j.first << "," << j.second << " ";
        //     cout << endl;
        // }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n,INT_MAX);
        dist[k-1] = 0;
        pq.push({0,k-1});
        while(pq.size()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto i : adj[node])
            {
                int edgeWeight = i.second;
                int adjNode = i.first;
                if(dist[adjNode] > dis + edgeWeight)
                {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        int ans = INT_MIN;
        for(auto i : dist){
            if(i == INT_MAX) return -1;
            ans = max(ans,i);
        }
        return ans;
    }
};