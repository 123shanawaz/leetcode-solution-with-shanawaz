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
    int kthSmallest(TreeNode* root, int k) { 
        return dfs(root, k);
    }
    int dfs(TreeNode* node, int& k){
        if(!node) return INT_MIN;
        int l = dfs(node->left,k);
        if(k == 0) return l;
        else if(k == 1){
            k--;
            return node->val;
        }
        else{
            k--;
            int r = dfs(node->right,k);
            if(k==0) return r;
            else return INT_MIN;   
        }
    }

};