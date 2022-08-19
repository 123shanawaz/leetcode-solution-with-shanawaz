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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
          vector<vector<int>>ans;
        solve( root, targetSum,temp,ans);
        return ans;
        
    }
    private:void solve(TreeNode* root, int targetSum, vector<int>temp,  vector<vector<int>>&ans){
        if(root==NULL){
            return;
        }
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL && root->val==targetSum){
            ans.push_back(temp);
        }
        solve(root->left,targetSum-root->val,temp,ans);
         solve(root->right,targetSum-root->val,temp,ans);
    
    }
};