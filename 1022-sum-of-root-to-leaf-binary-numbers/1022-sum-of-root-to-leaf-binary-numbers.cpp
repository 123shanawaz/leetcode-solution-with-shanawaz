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
    void totalleaf(TreeNode* root,string currentstring,int* ans){
        if(root->left==NULL && root->right==NULL){
            currentstring+=to_string(root->val);
            ans[0]+=stoi(currentstring,0,2);
            return;
        }
        string curr=to_string(root->val);
        if(root->left!=NULL){
            totalleaf(root->left,currentstring+curr,ans);
        }
        if(root->right!=NULL){
            totalleaf(root->right,currentstring+curr,ans);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        int* ans=new int[1];
        ans[0]=0;
        totalleaf(root,"",ans);
        return ans[0];
        
    }
};