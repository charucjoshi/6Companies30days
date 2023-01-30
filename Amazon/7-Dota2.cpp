class Solution {
public:
    string predictPartyVictory(string sen) {
        queue<int> qr, qd;
        int n = sen.size();
        for(int i = 0; i < n; ++i){
            (sen[i] == 'R') ? qr.push(i) : qd.push(i);
        }
        while(qr.size() && qd.size())
        {
            int r_ind = qr.front(); int d_ind = qd.front(); qr.pop(); qd.pop();
            (r_ind < d_ind) ? qr.push(r_ind+n) : qd.push(d_ind+n);
        }
        return (qr.size() > qd.size() ? "Radiant" : "Dire");
    }
};