class Solution {
public:
    void fun(int ind, int target, int k, vector<int> &v, vector<vector<int>> &ans, vector<int> &temp){
        if(target == 0)
        {
            if(temp.size() == k)
                ans.push_back(temp);
            return;
        }

        for(int i =ind; i < v.size(); ++i){
            if(i > ind && v[i] == v[i-1]) continue;
            if(v[i] > target) break;
            temp.push_back(v[i]);
            fun(i+1,target-v[i],k,v,ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> v = {1,2,3,4,5,6,7,8,9};
        fun(0,n,k,v,ans,temp);
        return ans;
    }
};