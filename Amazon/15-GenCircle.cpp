class Solution {
public:
    double r, x, y;
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    
    vector<double> randPoint() {
        double length;
        double theta;

        double random = (double) rand()/ RAND_MAX; 
        theta = random * 2 * 3.14159265359;

        double random1 = (double) rand()/RAND_MAX;
        length = sqrt(random1)*r;

        double x_r =x+ length*cos(theta);
        double y_r =y+ length*sin(theta);

        return vector<double> {x_r,y_r};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */