class Solution {
public:
    int min_price;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        min_price = directly_buy(price,needs);
        helper(price,special,needs,0,0);
        return min_price;
    }

    int directly_buy(vector<int> &price, vector<int> &needs){
        int total = 0;
        for(int i = 0; i < needs.size(); ++i){
            total += needs[i]*price[i];
        }
        return total;
    }
    bool can_use(vector<int> &offer, vector<int> &needs){
        for(int i = 0; i < needs.size(); ++i)
            if(needs[i] < offer[i]) return false;
        return true;
    }
    void helper(vector<int> &price, vector<vector<int>> &special, vector<int> &needs, int used, int index){
        if(used >= min_price) return;
        if(index == special.size()){
            used += directly_buy(price,needs);
            if(used < min_price)
                min_price = used;
            return;
        }
        vector<int> offer = special[index];
        if(can_use(offer,needs)){
            int n = needs.size();
            vector<int> updated_needs(n);
            for(int i = 0; i < n; ++i)
                updated_needs[i] = needs[i]-offer[i];
            helper(price,special,updated_needs,used+offer[n],index);
        }

        helper(price,special,needs,used,index+1);
    }
};