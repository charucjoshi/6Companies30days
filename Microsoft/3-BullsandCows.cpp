class Solution {
public:
    string getHint(string secret, string guess) {
        int x = 0;
        for(int i = 0; i < secret.length(); ++i)
        {
            if(secret[i] == guess[i])
                x++;
        }
        map<char,int> m;
        for(int i = 0; i < secret.length(); ++i)
            m[secret[i]]++;
        int y = 0;
        for(int i = 0; i < guess.length(); ++i)
        {
            if(m[guess[i]])
            {
                y++;
                m[guess[i]]--;
            }
        }

        y -= x;
        string ans = to_string(x) + "A" + to_string(y) + "B";
        return ans;
    }
};