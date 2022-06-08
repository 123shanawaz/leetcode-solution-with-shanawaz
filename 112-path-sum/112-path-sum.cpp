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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return pathsum(root,0,targetSum);
        
    }
    private: bool pathsum(TreeNode* root,int currsum,int targetSum){
        if(root==NULL){
            return false;
        }
        if(root->left==NULL && root->right==NULL){
            if((currsum+root->val)==targetSum){
                return true ;
            }
            else {
                return false;
            }
        }
        bool a= pathsum(root->left,currsum+root->val,targetSum);
           bool b= pathsum(root->right,currsum+root->val,targetSum);
        return a||b;
    }
};