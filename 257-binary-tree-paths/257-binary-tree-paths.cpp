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
        pathtree(root,"",ans);
        return ans;
        
    }
    private:void pathtree(TreeNode* root,string currpath, vector<string>&ans){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            currpath+=to_string(root->val);
            ans.push_back(currpath);
        }
        currpath+=to_string(root->val)+"->";
        pathtree(root->left,currpath,ans);
        pathtree(root->right,currpath,ans);
        

          return;      

        
    }
};