#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
class Solution {
public:
    #define ll long long
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        ll n = nums1.size();

        //store all elements indices for nums2
        vector<ll> pos(n);
        for(int i = 0; i < n; ++i)
            pos[nums2[i]] = i;
        
        pbds s;

        vector<ll> pre(n), suff(n);
        for(ll i = 0; i<n; ++i){
            ll curr_pos = pos[nums1[i]];

            //no of ind strictly less than currpos
            pre[i] = s.order_of_key(curr_pos);
            s.insert(curr_pos);
        }
        s.clear();

        for(ll i = n-1; i >= 0; --i){
            ll curr_pos = pos[nums1[i]];
            //strictly greater
            suff[i] = s.size()- s.order_of_key(curr_pos);
            s.insert(curr_pos);
        }

        ll ans = 0;
        for(ll i = 1; i <n-1;i++)
            ans+= pre[i]*suff[i];
        return ans;
    }
};