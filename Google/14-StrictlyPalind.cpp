class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        int low = 2;
        int high = n-2;
        bool flag = true;
        for(int i = low; i <= high; ++i){
            vector<int> v;
            int temp = n;
            while(temp != 0)
            {
                v.push_back(temp%i);
                temp /= i;
            }
            reverse(v.begin(),v.end());
            bool check = true;
            for(int i = 0; i < v.size()/2; ++i)
                if(v[i] != v[v.size()-i-1])
                {
                    check = false;
                    break;
                }
            if(check == false) return false;
        }
        return true;
    }
};