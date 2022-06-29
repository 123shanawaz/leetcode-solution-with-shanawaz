/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void populatedmap(TreeNode* currroot,TreeNode* currparent,unordered_map<TreeNode*,TreeNode*>&mp){
        if(currroot==NULL){
            return;
        }
        mp[currroot]=currparent;
        populatedmap(currroot->left,currroot,mp);
         populatedmap(currroot->right,currroot,mp);
        return;
        
        
    }
    void printnode(TreeNode* currnode,int k, set<TreeNode*>&s, unordered_map<TreeNode*,TreeNode*>&mp, vector<int>&ans){
        if(currnode==NULL || s.find(currnode)!=s.end()||k<0){
            return;
        }
        s.insert(currnode);
        if(k==0){
            ans.push_back(currnode->val);
            return;
        }
        printnode( currnode->left,k-1,s,mp,ans);
        printnode( currnode->right,k-1,s,mp,ans);
        printnode( mp[currnode],k-1,s,mp,ans);
        return;
        
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        set<TreeNode*>s;
        unordered_map<TreeNode*,TreeNode*>mp;
        populatedmap(root,NULL,mp);
        printnode(target,k,s,mp,ans);
        
        return ans;
        
    }
};