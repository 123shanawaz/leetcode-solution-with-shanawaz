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
     if(root==NULL)
     {
          return 0;
     }
        queue<TreeNode*>q;
        q.push(root);
       
        int d=0;
        
        while (!q.empty()) {
        d++;
            
            int realneed=q.size();
            for (int i=0; i<realneed; i++) {
                TreeNode*  need=q.front();
                
                q.pop();
                
                
                if (need->left!=NULL)
                {
                    q.push(need->left);
                }
                if (need->right!=NULL)
                {
                    q.push(need->right);
                }
            }
        }
    return d;
    }
    
};