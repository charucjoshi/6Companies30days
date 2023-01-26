#define pb push_back
class Solution {
public:
    vector<int> pre;
    Solution(vector<int>& w) {
        pre.pb(w[0]);
        for(int i = 1; i < w.size(); ++i){
            pre.pb(pre.back() + w[i]);
        }
    }
    
    int pickIndex() {
        int r_weight = rand()%pre.back();
        return upper_bound(pre.begin(), pre.end(), r_weight)-pre.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */