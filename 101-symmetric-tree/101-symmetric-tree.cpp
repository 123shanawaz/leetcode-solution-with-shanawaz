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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode* l=q.front();
            q.pop();
            TreeNode* r=q.front();
            q.pop();
            if(l!=NULL && r==NULL)return false;
            if(l==NULL && r!=NULL)return false;
            if(l&& r){
                if(l->val!=r->val)return false;
                q.push(l->left);
                q.push(r->right);
                q.push(l->right);
                q.push(r->left);
            }
        }
        return true;
        
    }
};