class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return "0";
        long long int N = (long long int) numerator;
        long long int D = (long long int) denominator;
        long long int remainder;
        string ans = "";
        if(N < 0 && D > 0 || N > 0 && D < 0)
            ans += "-";
        if ( N < 0)
            N*=-1;
        if(D < 0)
            D*=-1;
        stringstream sst;
        sst << N/D;
        string temp;
        sst >> temp;
        ans += temp;
        remainder = N%D;
        if(remainder == 0)
            return ans;
        ans += ".";
        map<long long int, int> m;
        int ind;
        bool flag = true;
        remainder *= 10;
        while(remainder != 0)
        {
            if(m.find(remainder) != m.end())
            {
                flag = false;
                ind = m[remainder];
                break;
            }
            sst.clear();
            
            sst << remainder/D;   
            sst >> temp;
            m[remainder] = ans.length();
            ans += temp;
            remainder = remainder % D;
            remainder *= 10;
        }
        if(flag) return ans;
        cout << ind << endl;
        cout << ans;
        string ret = "";
        for(int i = 0; i < ans.length(); ++i)
        {
            if(i == ind)
                ret += "(";
            ret += ans[i];
        }
        ret += ")";
        return ret;
    }
};