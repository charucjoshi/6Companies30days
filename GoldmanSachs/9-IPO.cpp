class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minH;
        priority_queue<int> maxH;
        
        for(int i = 0; i < capital.size(); ++i)
        {
            minH.push({capital[i],i});
        }

        while(k--){
            while(minH.size() && w >= minH.top().first )
            {
                maxH.push(profits[minH.top().second]);
                minH.pop();
            }

            if(maxH.empty())
                break;
            
            w += maxH.top();
            maxH.pop();
        }

        return w;
    }
};