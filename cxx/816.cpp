// 816. Ambiguous Coordinates

class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> res;
        for(int i = 1; i < S.size() - 2; ++i) {
            // [1, i], [i+1, size-2]
            string a = S.substr(1, i - 1 + 1);
            string b = S.substr(i + 1, S.size() - 2 - i);
            for(string s1 : make(a))
                for(string s2 : make(b)) {
                    res.push_back("(" + s1 + ", " + s2 + ")");
                }
        }
        return res;
    }

    vector<string> make(string s) {
        vector<string> res;
        int len = s.size();
        for (int i = 1; i < len; ++i) {
            if (i > 1 && s[0] == '0') continue;
            if (s[len - 1] == '0') continue;
            res.push_back(s.substr(0, i) + "." + s.substr(i, len - i));
        }
        if (s.size() == 1 || s[0] != '0') res.push_back(s);
        return res;
    }
};