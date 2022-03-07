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
    bool validate(TreeNode* root, long min, long max)
    {
		//return true if we reach the null node
        if(root==NULL) return true;
        
		//Range based approach, where range = [min val, max val]
        if(root->val <= min || root->val >= max) return false;
        
		//while calling function, we call with the updated range values for min and max
		//here root->val updates max value for the first call and updates min value for second call.
       bool lr= validate(root->left, min, root->val);
       bool rr= validate(root->right, root->val, max);
        return lr&rr;
    }
    bool isValidBST(TreeNode* root) {
        return validate(root,LONG_MIN,LONG_MAX);
    }
};