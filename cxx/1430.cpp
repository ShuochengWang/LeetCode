// 面试题 16.13. 平分正方形

class Solution {
public:
    vector<double> cutSquares(vector<int>& square1, vector<int>& square2) {
        double cx1 = square1[0] + 0.5 * square1[2];
        double cy1 = square1[1] + 0.5 * square1[2];
        double cx2 = square2[0] + 0.5 * square2[2];
        double cy2 = square2[1] + 0.5 * square2[2];
        
        double rx1, ry1, rx2, ry2;
        if (cx1 == cx2) {
            rx1 = rx2 = cx1;
            ry1 = min(square1[1], square2[1]);
            ry2 = max(square1[1] + square1[2], square2[1] + square2[2]);
        }
        else if (cy1 == cy2) {
            ry1 = ry2 = cy1;
            rx1 = min(square1[0], square2[0]);
            rx2 = max(square1[0] + square1[2], square2[0] + square2[2]);
        }
        else {
            double xielv = (cy2 - cy1) / (cx2 - cx1);
            if (xielv <= 1 && xielv >= -1) {
                rx1 = min(square1[0], square2[0]);
                rx2 = max(square1[0] + square1[2], square2[0] + square2[2]);
                // ax + b = y
                // b = y - ax
                double b = cy1 - xielv * cx1;
                ry1 = xielv * rx1 + b;
                ry2 = xielv * rx2 + b;
            }
            else {
                ry1 = min(square1[1], square2[1]);
                ry2 = max(square1[1] + square1[2], square2[1] + square2[2]);
                // ax + b = y
                // b = y - ax
                // x = (y - b) / a
                double b = cy1 - xielv * cx1;
                rx1 = (ry1 - b) / xielv;
                rx2 = (ry2 - b) / xielv;

                if (rx1 > rx2) {
                    swap(rx1, rx2);
                    swap(ry1, ry2);
                }
            }
        }

        vector<double> res;
        res.push_back(rx1);
        res.push_back(ry1);
        res.push_back(rx2);
        res.push_back(ry2);
        return res;
    }
};