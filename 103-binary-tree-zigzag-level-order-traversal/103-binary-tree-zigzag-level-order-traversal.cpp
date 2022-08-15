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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       queue< TreeNode*>q;
         vector<vector<int>>ans;
        if(root==NULL){
            return ans;
            
        }
        q.push(root);
        int count=0;
        while(!q.empty()){
            count++;
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
            if(count%2==0){
                  reverse(lavel.begin(),lavel.end());
            }
            ans.push_back(lavel);
        }
        return ans;
    }
};