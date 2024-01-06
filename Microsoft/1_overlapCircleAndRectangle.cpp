class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int distance = 0;
        int closeX = max(x1,min(xCenter,x2));
        int closeY = max(y1,min(yCenter,y2));
        distance = (closeX-xCenter)*(closeX-xCenter) + (closeY-yCenter)*(closeY-yCenter);
        return distance <= radius*radius;
    }
};
