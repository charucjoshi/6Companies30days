class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxLeft = 0;
        int minRight = INT_MAX;
        for(int i = 0; i < left.size(); ++i)
            maxLeft = max(maxLeft, left[i]);
        for(int i = 0; i < right.size(); ++i)
            minRight = min(minRight, right[i]);
        return max(maxLeft , n-minRight);
    }
};