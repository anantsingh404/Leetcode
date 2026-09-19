class Solution {
public:
double clamp(double value, double min, double max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
     double pX = clamp(xc, x1, x2);
    double pY = clamp(yc, y1, y2);

    // 2. Calculate the squared distance from (0,0)
   int distX = pX - xc;
        int distY = pY - yc;
        int distanceSquared = (distX * distX) + (distY * distY);


    // 3. Compare with squared radius
    double radiusSquared = r*r;

    return distanceSquared <= radiusSquared;
    
    }
};