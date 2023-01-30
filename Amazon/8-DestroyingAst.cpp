class Solution {
public:
    bool asteroidsDestroyed(long long int mass, vector<int>& asteroids) {
        long long int n = asteroids.size();
        sort(asteroids.begin(),asteroids.end());
        for(long long int i = 0; i < n; ++i){
            if(mass < asteroids[i]) return false;
            else{
                mass+= asteroids[i];
            }
        }
        return true;
    }
};