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
    TreeNode* ans;
    void help(TreeNode* root, int val){
        if(!root)
            return;
        if(root->val == val){
            ans = root;
            return;
        }
        if(val < root->val)
        help(root->left, val);
        else
        help(root->right, val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        help(root, val);
        return ans;
    }
};