class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
        vector<int> ans;
        int n = nums.size();
        int nq = queries.size();
        for(int i = 0; i < nq; ++i){
            int k = queries[i][0];
            int trim = nums[0].size() - queries[i][1];
            vector<pair<string,int>> temp;
            for(int j = 0; j < n; ++j)
                temp.push_back({nums[j].substr(trim),j});
           
            sort(temp.begin(),temp.end());
            ans.push_back(temp[k-1].second);  
        }
        return ans;
    }
};