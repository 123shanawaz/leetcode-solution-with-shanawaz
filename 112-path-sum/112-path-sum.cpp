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
        queue<TreeNode*>q;
        if(root==NULL){
            return false;
        }
        q.push(root);
        while(!q.empty()){
            TreeNode* p=q.front();
            q.pop();

            if(p->left==NULL && p->right==NULL){
                if(p->val==targetSum)return true;
            }
            if(p->left!=NULL){
                p->left->val+=p->val;
                q.push(p->left);
            }
             if(p->right!=NULL){
                p->right->val+=p->val;
                q.push(p->right);
            }
        }
        return false;
        
    }
};