class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = INT_MIN;
        pair<int,int> type;
        int count = 2, sum = 0, start = 0;
        for(int i = 0; i < n; ++i){
            if(count == 2){
                type.first = fruits[i];
                sum++;
                count--;
            }
            else if(count == 1){
                if(fruits[i] == type.first)
                    sum++;
                else{
                    start = i;
                    type.second = fruits[i];
                    count--;
                    sum++;
                }
            }
            else if(count == 0){
                if(fruits[i] == type.second) sum++;
                else if(fruits[i] == type.first){
                    sum++;
                    start = i;
                    int temp = type.first;
                    type.first = type.second;
                    type.second = temp;
                }
                else{
                    type.first = type.second;
                    type.second = fruits[i];
                    sum = (i-start+1);
                    start = i;
                }
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};