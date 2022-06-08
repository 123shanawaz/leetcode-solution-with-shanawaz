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
    int sumOfLeftLeaves(TreeNode* root) {
        return leftleavesum(root,false);
        
    }
    private:int leftleavesum(TreeNode* root,bool leaf){
        if(root==NULL){
            return 0;
        }
        if(root->left ==NULL && root->right==NULL && leaf==true){
            return root->val;
        }
        int ls=leftleavesum(root->left,true);
        int rs=leftleavesum(root->right,false);
        return ls+rs;
    }
};