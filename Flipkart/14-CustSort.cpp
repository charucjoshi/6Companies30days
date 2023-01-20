class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> m;
        for(int i = 0; i < order.length(); ++i)
            m[order[i]] = i+1;
     
        for(int i = 0; i < s.length()-1; ++i){
            int min = i;
            for(int j = i+1; j < s.length(); ++j){
                if(m.find(s[min]) != m.end() && m.find(s[j]) != m.end()){
                    if(m[s[min]] > m[s[j]]){
                        min = j;
                    }
                }
                else if(m.find(s[j]) != m.end()){
                    min = j;
                }
            }
    
            if(i != min){
                swap(s[min],s[i]);
            }
        }

        return s;
    }
};