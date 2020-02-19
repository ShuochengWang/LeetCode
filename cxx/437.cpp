// 437. Path Sum III

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
    int pathSum(TreeNode* root, int sum) {
        map<int, int> sum_map;
        sum_map[0] = 1;
        return dfs(root, sum, sum_map, 0);
    }

    int dfs(TreeNode* root, int sum, map<int, int>& sum_map, int pathsum) {
        if (!root) return 0;
        int res = 0;

        pathsum += root->val;
        int target = pathsum - sum;
        if (sum_map.find(target) != sum_map.end()) res += sum_map[target];

        if (sum_map.find(pathsum) != sum_map.end()) sum_map[pathsum]++;
        else sum_map[pathsum] = 1;

        res += dfs(root->left, sum, sum_map, pathsum) + dfs(root->right, sum, sum_map, pathsum);

        sum_map[pathsum]--;
        if (sum_map[pathsum] == 0) sum_map.erase(pathsum);

        return res;
    }
};