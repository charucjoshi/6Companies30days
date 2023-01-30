class Solution {
public:
    vector<int> ini;
    vector<int> v;
    int n;
    Solution(vector<int>& nums) {
        ini = nums;
        v = nums;
        n = nums.size();
    }
    
    vector<int> reset() {
        v = ini;
        return v;
    }
    
    vector<int> shuffle() {
        int last = n;
        while(last > 1){
            int ind = rand()%last;
            int temp = v[ind];
            v[ind] = v[last-1];
            v[last-1] = temp;
            last--;
        }
        return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */