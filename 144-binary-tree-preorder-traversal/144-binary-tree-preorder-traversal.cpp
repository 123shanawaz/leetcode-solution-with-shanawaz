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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>s;
        if(root==NULL)return ans;
        s.push(root);
        while(!s.empty()){
           TreeNode* currnode=s.top();
            s.pop();
            ans.push_back(currnode->val);
            if(currnode->right!=NULL){
                s.push(currnode->right);
            }
            if(currnode->left!=NULL){
                s.push(currnode->left);
            }
        }
        return ans;
        
    }
};