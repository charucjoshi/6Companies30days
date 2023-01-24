class Solution {
public:
    void merge(vector<int>& nums,int start, int mid, int end){
        int nl = mid-start+1;
        int nr = end-mid;
        vector<int> left(nl), right(nr);
        for(int i = 0; i < nl; ++i)
            left[i] = nums[start+i];
        for(int i = 0; i < nr; ++i)
            right[i] = nums[mid+1+i];
        int il = 0, ir = 0, i = start;
        while(il < nl && ir < nr){
            if(left[il] <= right[ir]){
                nums[i] = left[il];
                i++;
                il++;
            }
            else{
                nums[i] = right[ir];
                i++;
                ir++;
            }
        }
        while(il < nl)
            nums[i++] = left[il++];
        while(ir < nr)
            nums[i++] = right[ir++];
    }
    void merge_sort(vector<int>& nums, int start, int end){
        if(start >= end) return;
        int mid = start+(end-start)/2;
        merge_sort(nums,start,mid);
        merge_sort(nums,mid+1,end);
        merge(nums,start,mid,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        merge_sort(nums,0,n-1);
        return nums;
    }
};