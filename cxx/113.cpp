// 113. Path Sum II

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, root, sum, path);
        return res;
    }

    void dfs(vector<vector<int>>& res, TreeNode* node, int sum, vector<int>& path) {
        if (!node) return;
        if (node->val == sum && !node->left && !node->right) {
            path.push_back(node->val);
            res.push_back(path);
            path.pop_back();
            return;
        }
        
        if (node->left) {
            path.push_back(node->val);
            dfs(res, node->left, sum - node->val, path);
            path.pop_back();
        }
        if (node->right) {
            path.push_back(node->val);
            dfs(res, node->right, sum - node->val, path);
            path.pop_back();
        }
    }
};