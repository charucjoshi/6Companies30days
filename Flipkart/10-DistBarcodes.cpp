class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        map<int,int> m;
        for(auto i : barcodes)
            m[i]++;
        priority_queue<pair<int,int>> pq;
        for(auto i : m){
            pq.push({i.second,i.first});
        }
        vector<int> ans(barcodes.size());
        int n = barcodes.size();
        int k = 0;
        
        vector<int> temp;
        while(pq.size()){
            int count = pq.top().first;
            while(count--)
                temp.push_back(pq.top().second);
            pq.pop();
        }
        vector<bool> isit(n,true);
        int t = 0;
        for(int i = 0; i < temp.size(); i++){   
            for(int k = i; k < temp.size(); k+=2){
                if(t >= n) break;
                if(isit[k])
                {
                    isit[k] = false;
                    ans[k] =  temp[t++];
                }
                else k--;
            }
            if(t >= n) break;
        }
        return ans;
    }
};