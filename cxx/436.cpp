// 436. Find Right Interval

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> res(intervals.size(), -1);
        for (int i = 0; i < intervals.size(); ++i)
            intervals[i].push_back(i);
        sort(intervals.begin(), intervals.end(), cmp);

        for (int i = 0; i < intervals.size() - 1; ++i) {
            int target = intervals[i][1];
            int lo = i + 1;
            int hi = intervals.size() - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (intervals[mid][0] < target) lo = mid + 1;
                else if (intervals[mid][0] == target) {
                    res[intervals[i][2]] = intervals[mid][2];
                    break;
                }
                else {
                    res[intervals[i][2]] = intervals[mid][2];
                    hi = mid - 1;
                }
            }
        }
        return res;
    }

    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0]) return a[0] < b[0];
        else return a[1] < b[1];
    }
};