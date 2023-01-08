class Solution {
public:
    bool isValid(int numArrows, vector<int> arr, int mask){
        int score = 11;
        int count = 0;
        while(mask > 0){
            if((mask & 1) == 1)
                count+=(arr[score]+1);
            score--;
            mask>>=1;
        }
        return count <= numArrows;
    }
    int calc(int mask){
        int score = 11;
        int ret = 0;
        while(mask > 0){
            if(mask&1==1)
                ret += score;
            score--;
            mask>>=1;
        }
        return ret;
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int N = (1<<12)-1;
        int maxi = INT_MIN;
        int mask = 0;
        for(int i = 1; i <= N; ++i){
            if(isValid(numArrows,aliceArrows,i))
            {
                int points = calc(i);
                if(points > maxi)
                {
                    maxi = points;
                    mask = i;
                }
            }
        }

        vector<int> bob(12,0);
        int score = 11;
        int c = 0;
        while(mask>0){
            if(mask&1==1)
            {
                bob[score] = aliceArrows[score]+1;
                c += bob[score];
            }
            score--;
            mask>>=1;
        }
        bob[0]= numArrows-c;
        return bob; 
    }
};