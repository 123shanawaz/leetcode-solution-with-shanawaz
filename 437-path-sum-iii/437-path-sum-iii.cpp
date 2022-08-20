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
    int total=0;
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return 0;
        }
        dfs(root,targetSum,0);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return total;
    }
    private:void dfs(TreeNode* root, long long targetSum,long long currsum){
        if(root==NULL)return;
        currsum+=root->val;
        if(currsum==targetSum){
            total++;
        }
        dfs(root->left,targetSum,currsum);
         dfs(root->right,targetSum,currsum);
        return ;
    }
};