class Solution {
public:
    double calculateDistance(double x1, double y1, double x2, double y2) {
        double dx = x2 - x1;
        double dy = y2 - y1;
        return sqrt(dx * dx + dy * dy);
    }
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                      int x2, int y2) {

        int closeX, closeY;

        closeX = max(x1, min(x2, xCenter));
        closeY = max(y1, min(y2, yCenter));

        return calculateDistance(xCenter,yCenter,closeX,closeY) <= radius;
    }
};