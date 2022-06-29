/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==p->val || root->val==q->val){
            return root;
        }
       TreeNode* leftsubtree= lowestCommonAncestor(root->left,p,q);
        TreeNode* rightsubtree= lowestCommonAncestor(root->right,p,q);
        if(leftsubtree!=NULL && rightsubtree!=NULL){
            return root;
        }
        if(leftsubtree!=NULL){
            return leftsubtree;
        }
        if(rightsubtree!=NULL){
            return rightsubtree;
        }
        return NULL;
        
    }
};