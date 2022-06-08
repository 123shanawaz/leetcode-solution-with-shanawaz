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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        Btpath(root,"",ans);
        return ans;
        
    }
    private: void Btpath(TreeNode* root,string currpath,vector<string>&ans){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            currpath+=to_string(root->val);
            ans.push_back(currpath);
            return;
        }
        currpath+=to_string(root->val)+"->";
        Btpath(root->left,currpath,ans);
        Btpath(root->right,currpath,ans);
        
        return;
    }
};