class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Making an adjacency list
    
        vector<pair<int,long>> adj[n];
        for(auto i : roads)
        {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        
        // Simple Dijkstra with ways[]
        long mod = 1e9+7;
        vector<long> ways(n,0), dist(n, LONG_MAX);
        priority_queue<pair<long,int>, vector<pair<long,int>>, greater<pair<long,int>>> pq;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        while(pq.size()){
            
            int node = pq.top().second;
            long sourceDist = pq.top().first;
            pq.pop();
            for(auto it : adj[node]){
                
                if(sourceDist + it.second < dist[it.first])
                {
                    dist[it.first] = sourceDist + it.second;
                    ways[it.first] = ways[node];
                    pq.push({dist[it.first],it.first});
                }
                else if(sourceDist + it.second == dist[it.first])
                {
                    ways[it.first] = (ways[it.first] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};