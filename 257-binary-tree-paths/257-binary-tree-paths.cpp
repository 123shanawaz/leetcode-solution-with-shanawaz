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
    void pathfinder(TreeNode* root,vector<string>&ans,string currpath){
        if(root->left==NULL && root->right==NULL){
            currpath+=to_string(root->val);
            ans.push_back(currpath);
            return ;
        }
        currpath+=to_string(root->val)+"->";
        if(root->left) pathfinder(root->left,ans,currpath);
         if(root->right) pathfinder(root->right,ans,currpath);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        pathfinder(root,ans,"");
        return ans;
        
        
    }
};