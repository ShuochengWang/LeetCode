// 126. Word Ladder II

class Solution {
public:
    void help(vector<string>& wordList, map<string, pair<int, int>>& m, vector<vector<int>>& previousWord, string& cur, stack<string>& path, vector<vector<string>>& res, string& beginWord) {
        if (previousWord[m[cur].first].empty()) {
            path.push(beginWord);
            vector<string> vec;
            while (!path.empty()) {
                vec.push_back(path.top());
                path.pop();
            }
            res.push_back(vec);
            return;
        }
        for (int x = 0; x < previousWord[m[cur].first].size(); ++x) {
            int next = previousWord[m[cur].first][x];
            stack<string> new_path(path);
            new_path.push(wordList[next]);
            help(wordList, m, previousWord, wordList[next], new_path, res, beginWord);
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        map<string, pair<int, int>> m;
        vector<vector<int>> previousWord(wordList.size(), vector<int>());
        for (int i = 0; i < wordList.size(); ++i) m[wordList[i]] = pair<int, int>(i, -1);
        if (m.find(endWord) == m.end()) return res;
        queue<pair<string, int>> q;
        q.push(pair<string, int>(beginWord, 0));
        int max_len = wordList.size() + 1;
        while (!q.empty()) {
            string word = q.front().first;
            int order = q.front().second;
            q.pop();
            if (order + 1 >= max_len) break;
            bool canbreak = false;
            for (int i = 0; i < word.size(); ++i) {
                for (int ch = 'a'; ch <= 'z'; ++ch) {
                    if (word[i] == ch) continue;
                    string tmp = word;
                    tmp[i] = ch;
                    if (tmp == endWord) {
                        if (word == beginWord) {
                            vector<string> vec;
                            vec.push_back(beginWord);
                            vec.push_back(endWord);
                            res.push_back(vec);
                            return res;
                        }
                        stack<string> stk;
                        stk.push(endWord);
                        stk.push(word);
                        help(wordList, m, previousWord, word, stk, res, beginWord);
                        max_len = res[0].size();
                        canbreak = true;
                        break;
                    }
                    if (m.find(tmp) != m.end()) {
                        if (m[tmp].second == -1) {
                            q.push(pair<string, int>(tmp, order + 1));
                            m[tmp].second = order + 1;
                            if (word != beginWord) {
                                previousWord[m[tmp].first].push_back(m[word].first);
                            }
                        }
                        else if (m[tmp].second < order + 1) continue;
                        else {
                            previousWord[m[tmp].first].push_back(m[word].first);
                        }
                    }
                }
                if (canbreak) break;
            }
        }
        return res;
    }
};