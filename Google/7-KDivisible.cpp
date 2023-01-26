class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
          int ans = 0;
          set<string> s;
          for(int i = 0; i < nums.size(); ++i){
              int count = 0;
              string temp="";
              for(int j = i; j < nums.size(); ++j){
                  if(nums[j]%p == 0) count++;
                  if(count > k) break;
                  temp += to_string(nums[j]);
                  temp += "-";
                  s.insert(temp);
              }
          }
          return s.size();    
    }
};