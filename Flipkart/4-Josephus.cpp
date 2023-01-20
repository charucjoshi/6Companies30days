class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> arr(n);
        for(int i = 0; i < n; ++i)
            arr[i] = i+1;
    
        return helper(0,k-1,arr,n);
    }
    int helper(int start_idx, int k, vector<int> &arr, int size){
        if(size == 1) return arr[0];
    
        int los_idx = (start_idx + k) % size;
        vector<int> updated_arr(size-1);
        int j = 0;
        for(int i = 0; i < size; ++i){
            if(i != los_idx)
                updated_arr[j++] = arr[i];
        }
        return helper(los_idx, k, updated_arr, size-1);
    }
};