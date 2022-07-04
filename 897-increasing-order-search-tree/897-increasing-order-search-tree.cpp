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
    void preorder(TreeNode* root,vector<int>&ans){
        if(root==NULL){
            return ;
        }
        preorder(root->left,ans);
        ans.push_back(root->val);
        preorder(root->right,ans);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>ans;
        preorder(root,ans);
        TreeNode* dummy=new TreeNode(-1);
        TreeNode* newNode=dummy;
        for(auto it:ans){
            dummy->right=new TreeNode(it);
            dummy=dummy->right;
        }
        return newNode->right;
        
        
    }
};