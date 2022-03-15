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
TreeNode *ConstructTree(vector<int>&postorder,unordered_map<int,int>&mp,int start,int end,int &currentidx){
        if(start>end)return NULL;
        TreeNode *rootNode=new TreeNode(postorder[currentidx]);
        int inDidx=mp[postorder[currentidx]];
        currentidx--;
        
        rootNode->right=ConstructTree(postorder,mp,inDidx+1,end,currentidx);
        rootNode->left=ConstructTree(postorder,mp,start,inDidx-1,currentidx);
        return rootNode;
    }
     unordered_map<int,int>inorderindex(vector<int>&inorder){
         unordered_map<int,int>mp;
         for(int i=0;i<inorder.size();i++){
             mp[inorder[i]]=i;
             
         }
         return mp;
     }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       unordered_map<int,int>mp=inorderindex(inorder);
        int currentidx=postorder.size()-1;
          return ConstructTree(postorder,mp,0,inorder.size()-1,currentidx);
        
    }
};