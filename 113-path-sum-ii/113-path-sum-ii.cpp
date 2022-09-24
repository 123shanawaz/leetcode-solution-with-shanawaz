/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> curr;
        vector<vector<int>> result;
        
        dfs_preorder(root, curr, result, 0, sum);
        
        return result;
    }
    
    void dfs_preorder(TreeNode* root, vector<int> curr, vector<vector<int>>& result, int total, int sum){
        if(!root) return;
        
        total += root->val;
        curr.push_back(root->val);
        
        if(!root->left && !root->right && total == sum){
            result.push_back(curr);
        }
        
        dfs_preorder(root->left, curr, result, total, sum);
        dfs_preorder(root->right, curr, result, total, sum);
    }
};