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
   
    int pseudoPalindromicPaths (TreeNode* root) {
         int res=0;
        vector<int>mp(10,0);
        palindromicpath(root,mp,res);
        return res;
        
        
    }
    private: void  palindromicpath(TreeNode* root,vector<int>&mp,int &res){
        if(root==NULL){
            return ;
        }
        mp[root->val]++;
         palindromicpath(root->left,mp,res);
         palindromicpath(root->right,mp,res);
        if(root->right==NULL && root->left==NULL){
            int count=0;
            for(int i=1;i<10;i++){
                if(mp[i]%2!=0){
                    count++;
                }
            }
            if(count==1 || count==0)res++;
        }
        mp[root->val]--;
        return ;
    }
};