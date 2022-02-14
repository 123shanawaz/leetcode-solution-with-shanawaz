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
    void Rview(TreeNode *root,set<int>&s,vector<int>&ans,int currlavel){
    if(root==NULL){
        return ;
    }
    if(s.find(currlavel)==s.end()){
        s.insert(currlavel);
        ans.push_back(root->val);
    }
    Rview(root->right,s,ans,currlavel+1);
    Rview(root->left,s,ans,currlavel+1);
    return ;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        set<int>s;
        Rview(root,s,ans,0);
        return ans;
    }
};