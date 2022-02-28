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
     void preorderLeafSequence(TreeNode* root,vector<int> & v)
    {
        if(root==NULL)
            return;
        // if the node is NULL store it in the vector
		if(root->left==NULL && root->right==NULL)
            v.push_back(root->val);
        // preorder traversal steps
		preorderLeafSequence(root->left,v);
        preorderLeafSequence(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
       // two vectors to store leaf sequence
	   vector<int>  v1,v2;
        preorderLeafSequence(root1,v1);
        preorderLeafSequence(root2,v2);
		// if vector are of different size return false
        if(v1.size()!=v2.size())
            return false;
		
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]!=v2[i])
                return false;
        }
		// if all elements of the vector are same return true
        return true;
    }
        
    

};