// LCP 3. 机器人大冒险

class Solution {
public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        set<pair<int, int>> path;
        int dx = 0, dy = 0;
        path.insert(make_pair(dx, dy));
        for (auto ch : command) {
            if (ch == 'R') dx++;
            else dy++;
            path.insert(make_pair(dx, dy));
        }

        int eturn = min(x / dx, y / dy);
        int ex = x - eturn * dx;
        int ey = y - eturn * dy;
        if (path.find(make_pair(ex, ey)) == path.end()) return false;

        for (int i = 0; i < obstacles.size(); ++i) {
            int tx = obstacles[i][0];
            int ty = obstacles[i][1];
            int tturnx = tx / dx;
            int tturny = ty / dy;
            int tturn = min(tturnx, tturny);
            if (abs(tturnx - tturny) <= 1 && tturn <= eturn) {
                tx -= tturn * dx;
                ty -= tturn * dy;
                if (tturn == eturn && !(tx <= ex && ty <= ey)) continue;
                if (path.find(make_pair(tx, ty)) != path.end()) return false;
            }
        }
        return true;       
    }
};