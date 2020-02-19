// 面试题59 - I. 滑动窗口的最大值

// 单调队列

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < nums.size(); ++i) {
            while(!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
            if(!q.empty() && q.front() <= i - k) 
                q.pop_front();
            q.push_back(i);
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};