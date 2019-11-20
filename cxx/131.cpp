// 131. Palindrome Partitioning

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s == "") return res;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < dp.size(); ++i) dp[i][i] = 1;
        for (int i = 0; i < dp.size(); ++i) {
            for (int j = i + 1; j < dp[0].size(); ++j) {
                int beg = i, end = j;
                while (beg < dp.size() && end >= 0 && s[beg] == s[end]) {
                    beg++;
                    end--;
                }
                if (beg >= end) dp[i][j] = 1;
            }
        }
        vector<string> vec;
        help(res, s, dp, vec, 0);
        return res;
    }

    void help(vector<vector<string>>& res, string& s, vector<vector<int>>& dp, vector<string>& vec, int pos) {
        if (pos > s.size() - 1) {
            res.push_back(vec);
            return;
        }
        for (int i = pos; i < s.size(); ++i) {
            if (dp[pos][i]) {
                vector<string> new_vec(vec);
                new_vec.push_back(s.substr(pos, i - pos + 1));
                help(res, s, dp, new_vec, i + 1);
            }
        }
    }
};