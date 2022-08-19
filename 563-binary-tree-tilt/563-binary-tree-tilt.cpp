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
    int findTilt(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
        
    }
    private:int solve(TreeNode* root,int &ans){
        if(root==NULL){
            return 0;
        }
        int l=solve(root->left,ans);
        int r=solve(root->right,ans);
        ans+=abs(l-r);
        return (r+l+root->val);
    }
};