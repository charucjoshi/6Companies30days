class Solution {
public:
    bool diff(string &a, string &b){
        if(a.length() != b.length()) return false;
        int count = 0;
        for(int i = 0; i < a.length(); ++i)
            if(a[i] != b[i])
                count++;
        return (count == 1);
    }
    int minMutation(string start, string end, 
    vector<string>& bank){
        int n = bank.size();
        map<string, vector<string>> adj;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; ++j){
                if(diff(bank[i],bank[j])){
                adj[bank[i]].push_back(bank[j]);
                adj[bank[j]].push_back(bank[i]);}
            }
        }
        for(int i = 0; i < n; ++i){
            if(diff(bank[i],start)){
                adj[bank[i]].push_back(start);
                adj[start].push_back(bank[i]);
            }
        }
        int ans = 0;
        queue<string> q;
        set<string> s;
        q.push(start);
        s.insert(start);
        while(q.size()){
            int size = q.size();
            while(size--){
                string u = q.front(); q.pop();
                for(auto i : adj[u]){
                    if(s.count(i) == 0)
                    {
                        q.push(i);
                        s.insert(i);
                    }
                }
            }
            ans++;
            if(s.count(end)) return ans;
        }
        return -1;
        return 0;
    }
};