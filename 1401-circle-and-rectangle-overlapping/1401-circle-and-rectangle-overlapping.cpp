class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xc = clamp(xCenter, x1, x2);
        int yc = clamp(yCenter, y1, y2);

        return pow(xCenter-xc, 2) + pow(yCenter-yc, 2) <= radius*radius;
    }
};