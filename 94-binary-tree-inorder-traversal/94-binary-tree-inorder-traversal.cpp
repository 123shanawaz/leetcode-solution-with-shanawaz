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
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode*> s;
        pushAllLeft(s, root);
        vector<int> result;
        while(!s.empty()) {
            TreeNode* p = s.top();
            s.pop();
            result.push_back(p->val);
            pushAllLeft(s,p->right);
        }
        return result;
    }
    
    void pushAllLeft(stack<TreeNode*>& s, TreeNode* root) {
        while(root!=NULL) {
            s.push(root);
            root = root->left;
        }
    }
};