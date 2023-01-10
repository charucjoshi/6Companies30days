class Solution {
public:
    class Attributes{
        public:
        string name;
        string city;
        int time;
        int amount;
    };
    Attributes parse(string transaction){
        Attributes obj;
        obj.name = ""; obj.city = "";
        string time_str = "";
        string amount_str = "";
        int c = 0;
        for(int i = 0; i < transaction.length(); ++i)
        {
            if(transaction[i] == ',')
            {
                c++;
            }
            else if(c == 0)
            {
                obj.name += transaction[i];
            }
            else if(c == 1)
            {
                time_str += transaction[i];
            }
            else if(c == 2)
            {
                amount_str += transaction[i];
            }
            else
            {
                obj.city += transaction[i];
            }
        }
        obj.time = stoi(time_str);
        obj.amount = stoi(amount_str);
        return obj;
    }
    bool condition(Attributes a, Attributes b){
        if(a.name == b.name && a.city != b.city)
        {
            if(abs(a.time-b.time) <= 60)
                return true;
        }
        return false;
    }
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> s;
        vector<bool> check(transactions.size(),false);
        int n = transactions.size();
        for(int i = 0; i < n-1; ++i){
            int flag = false;
            Attributes ob1 = parse(transactions[i]); 
            for(int j = i+1; j < n; ++j)
            {
                Attributes ob2 = parse(transactions[j]);
                if(condition(ob1,ob2))
                {
                    if(!check[i])
                    {
                        check[i] = true;
                        s.push_back(transactions[i]);
                    }
                    if(!check[j]){
                        check[j] = true;
                        s.push_back(transactions[j]);
                    }
                }
                if(ob1.amount > 1000 && !check[i])
                {    
                    s.push_back(transactions[i]);
                    check[i] = true;
                }
                if(ob2.amount > 1000 && !check[j])
                {
                    s.push_back(transactions[j]);
                    check[j] = true;
                }
            }
        }
        return s;
    }
};