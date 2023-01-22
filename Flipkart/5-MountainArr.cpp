/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int find_peak(MountainArray &mount,int beg,int end){
        int mid = (beg+end)/2;
        if(mount.get(mid)>mount.get(mid+1) && mount.get(mid) > mount.get(mid-1)) return mid;
        if(mount.get(mid)>mount.get(mid+1) && mount.get(mid)<mount.get(mid-1)) return find_peak(mount,beg,mid-1);
        if(mount.get(mid)<mount.get(mid+1)&&mount.get(mid)>mount.get(mid-1))
            return find_peak(mount,mid+1,end);
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        //Finding the peak index
        int n=mountainArr.length();
        int index;
        index = find_peak(mountainArr,1,n-1);
        
        int f = bin_search(mountainArr,0,index,target);
        int s = bin_search_rev(mountainArr,index+1,n-1,target);
        if(f != -1)
            return f;
        if(s != -1)
            return s;
        return -1;
    }
    int bin_search(MountainArray &mount, int beg, int end, int target){
        if(beg <= end){
            int mid = beg + (end-beg)/2;
            if(mount.get(mid) == target)
                return mid;
            else if(target < mount.get(mid))
                return bin_search(mount,beg,mid-1,target);
            else
                return bin_search(mount,mid+1,end,target);
        }
        return -1;
    }
    int bin_search_rev(MountainArray &mount, int beg, int end, int target){
        if(beg<=end){
            int mid = beg +(end-beg)/2;
            if(mount.get(mid) == target) return mid;
            else if(target < mount.get(mid))
                return bin_search_rev(mount,mid+1,end,target);
            else
                return bin_search_rev(mount,beg,mid-1,target);
        }
        return -1;
    }
};