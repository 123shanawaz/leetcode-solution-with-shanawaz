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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>a;
        vector<int>b;
        isSame(root1,a);
        isSame(root2,b);
        return a==b;
    }
    private:void isSame(TreeNode* root, vector<int>&v){
        if(root==NULL)return ;
        if(root->left==NULL && root->right==NULL){
            v.push_back(root->val);
        }
        if(root->left!=NULL){
            isSame(root->left,v);
        }
        if(root->right!=NULL){
            isSame(root->right,v);
        }
        return;
    }
};