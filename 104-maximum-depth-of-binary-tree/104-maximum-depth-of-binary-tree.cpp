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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int lavel=0;
        while(!q.empty()){
            lavel+=1;
            int currentsize=q.size();
            for(int i=0;i<currentsize;i++){
            TreeNode *currNode=q.front();
            q.pop();
            if(currNode->left!=NULL){
                q.push(currNode->left);
            }
                if(currNode->right!=NULL){
                    q.push(currNode->right);
                }
                
        }
        }
        return lavel;
        
    }
};