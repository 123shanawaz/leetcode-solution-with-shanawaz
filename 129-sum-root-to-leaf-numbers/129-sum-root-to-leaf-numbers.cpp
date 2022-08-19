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
    int sumNumbers(TreeNode* root) {
       return solve(root,0);
        
        
    }
    private: int solve(TreeNode* root,int curr){
        if(root==NULL){
            return 0;
        }
        curr=curr*10+root->val;
        if(root->left==NULL && root->right==NULL){
            return curr;
        }
        int a=solve(root->left,curr);
        int b=solve(root->right,curr);
        return a+b;
    }
};