class Solution {
public:
    int count(long cur, int n){
        long next = cur + 1;
        long total = 0;
        while(cur <= n){
            total += min(n-cur+1, next - cur);
            cur*=10;
            next*=10;
        }
        return (int) total;
    }
    int findKthNumber(int n, int k) {
        long cur = 1;
        k--;
        while(k > 0)
        {
            int nodes = count(cur, n);
            if(k >= nodes){
                cur++;
                k-=nodes;
            }
            else{
                k--;
                cur *= 10;
            }
        }

        return (int) cur;
    }
};