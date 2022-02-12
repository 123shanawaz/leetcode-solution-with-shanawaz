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
    void getleavs(TreeNode* root,vector<int>&v){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            v.push_back(root->val);
        }
        getleavs(root->left,v);
        getleavs(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>a,b;
        getleavs(root1,a);
        getleavs(root2,b);
        return a==b;
        
    }
};