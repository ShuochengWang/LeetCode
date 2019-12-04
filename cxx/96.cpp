// 96. Unique Binary Search Trees

class Solution {

public:
    int numTrees(int n) {
        if (n <= 1) return 1;
        int* dp = new int [n + 1];
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = 0;
            for (int j = 1; j <= i; ++j)
                dp[i] += dp[j - 1] * dp[i - j];
        }
        int res = dp[n];
        delete[] dp;
        return res;
    }
};