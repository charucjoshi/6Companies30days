class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> v(right+1,true);
        for(int i = 2; i <= right; ++i){
            if(v[i]){
                for(int j = 2*i; j <= right; j += i)
                    v[j] = false;
            }
        }
        int first;
        bool flag = true;
        if(left < 2) left = 2;
        for(int i = left; i <= right; ++i){
            if(v[i])
            {
                flag = false;
                cout << i << endl;
                first = i;
                break;
            }
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = first + 1; i <= right; ++i){
            int second=i;
            if(v[i]){
                pq.push({second-first,first});
                first = second;
            }
        }
        
        if(pq.size() == 0 || flag) return {-1,-1};
        
        vector<int> ans(2);
        ans[0] = pq.top().second;
        ans[1] = pq.top().second + pq.top().first;
        return ans;
    }
};