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
// class Solution {
// public:
//     void preorder(TreeNode *root, vector<int>&ans){
//          if(root==NULL){
//             return ;
//         }
//         ans.push_back(root->val);
//         preorderTraversal(root->left,ans);
//         preorderTraversal(root->right,ans);
//         return ;
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//        vector<int>ans;
//        preorder(root,ans);
//         return ans;
        
//     }
// };

class Solution {
public:
    void Preorder(TreeNode *root,vector<int>&ans){
        if(root == NULL) return;
        
        ans.push_back(root->val);
        Preorder(root->left,ans);
        Preorder(root->right,ans);
        
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        Preorder(root,ans);
        return ans;
        
    }
};