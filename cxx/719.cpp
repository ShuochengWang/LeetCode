// 719. Find K-th Smallest Pair Distance

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums[nums.size()-1] - nums[0];
        while (low < high) {
            double guess = (high + low) / 2;
            if (inhere(nums, k, guess)) high = guess;
            else low = guess + 1;
        }
        return low;
    }

    bool inhere(vector<int>& nums, int k, double guess) {
        int left = 0;
        int count = 0;
        for (int right = 0; right < nums.size(); ++right) {
            while (nums[right] - nums[left] > guess) left++;
            count += right - left;
        }
        return count >= k;
    }
};