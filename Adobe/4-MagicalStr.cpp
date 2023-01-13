class Solution {
public:
    int magicalString(int n) {
        //Building the Magical String
        // Size = 3 ---> 122
        // Size = 4 ---> 1221
        string mag_str = "122";
        int next = 1;
        int repeat = 2;
        int ind = 2;
        while(mag_str.length() <= n){
            
            if(next == 1){
                if(mag_str[ind] == '1')
                    mag_str += "1";
                else
                    mag_str += "11";
                ind++;
                next = 2;
            }
            else{
                if(mag_str[ind] == '1')
                    mag_str += "2";
                else
                    mag_str += "22";
                ind++;
                next = 1;
            }
        }
        
        // Find the answer
        int ans = 0;
        for(int i = 0; i < n; ++i)
            if(mag_str[i] == '1')
                ans++;

        return ans;
    }
};