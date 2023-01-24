class Solution {
public:
    int countCurr(vector<int> &roles, int mask){
        int count = 0;
        for(int i = 0; i < roles.size(); ++i){
            count += roles[i] = mask&1;
            mask>>=1;
        }
        return count;
    }
    bool valid(vector<vector<int>> &st, vector<int> &roles){
        for(int i = 0; i < st.size(); ++i){
            if(roles[i] == 0) continue;

            for(int j = 0; j < st.size(); ++j){
                if(st[i][j] == 2) continue;
                if(st[i][j] != roles[j]) return false;
            }
        }
        return true;
    }
    int maximumGood(vector<vector<int>>& st) {
        int n = st.size();
        int maxGood = 0;
        int com = 1<<n;
        vector<int> roles(n);
        for(int mask = 1; mask < com; ++mask){
            int currGood = countCurr(roles,mask);
            if(valid(st,roles))
                maxGood = max(maxGood,currGood);
        }
        return maxGood;
    }
};