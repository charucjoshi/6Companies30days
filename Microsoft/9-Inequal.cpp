class Solution {
public:
    long long ans = 0;
    void merge(vector<int>& v, int start, int mid, int end, int diff){
        int l = start, r = mid+1;
        while(l <= mid && r <= end){
            if(v[l] <= v[r] + diff)
            {
                ans += (end-r+1);
                l++;
            }
            else r++;
        }
        sort(v.begin()+start, v.begin()+end+1);
        
    }
    void mergeSort(vector<int>& v, int start, int end, int diff){
        if(start == end)
            return;
        int mid = (start+end)/2;
        mergeSort(v,start,mid,diff);
        mergeSort(v,mid+1,end,diff);

        merge(v,start,mid,end,diff);
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int> v(nums1.size());
        for(int i = 0; i < nums1.size(); ++i)
        {
            v[i] = nums1[i] - nums2[i];
        }
        mergeSort(v,0,nums1.size()-1,diff);
        return ans;
    }
};