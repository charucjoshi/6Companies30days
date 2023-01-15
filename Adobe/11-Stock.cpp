class StockPrice {
public:
    map<int,int> m;
    map<pair<int,int>, int> mmap;
    StockPrice() {
        
    }
    
    void update(long long timestamp, long long price) {
        if(m.find(timestamp) != m.end())
            mmap.erase({m[timestamp],timestamp});
        m[timestamp] = price;
        mmap[{price,timestamp}] = timestamp;
    }
    
    int current() {
        return (int)m.rbegin()->second;
    }
    
    int maximum() {
        return (int)mmap.rbegin()->first.first;
    }
    
    int minimum() {
        return mmap.begin()->first.first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */