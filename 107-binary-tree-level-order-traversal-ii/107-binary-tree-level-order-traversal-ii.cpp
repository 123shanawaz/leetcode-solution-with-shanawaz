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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(root==NULL ){
            return ans;
        }
        
        q.push(root);
       
        while(!q.empty()){
           int currsize=q.size();
            vector<int>lavel;
            while(currsize>0){
                TreeNode* node=q.front();
                q.pop();
                lavel.push_back(node->val);
                currsize--;
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            ans.push_back(lavel);
           
        }
         reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};