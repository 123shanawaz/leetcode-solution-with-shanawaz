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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*>store;
        store.push(p);
        store.push(q);
        while(!store.empty()){
            TreeNode* LT=store.front();
            store.pop();
            TreeNode* RT=store.front();
            store.pop();
            if(RT!=NULL && LT==NULL)return false;
            if(RT==NULL && LT!=NULL)return false;
            if(LT!=NULL && RT!=NULL){
             if( RT->val!=LT->val )return false;
            store.push(RT->left);
            store.push(LT->left);
            store.push(RT->right);
            store.push(LT->right);
        }
        }
     return true;   
    }
};