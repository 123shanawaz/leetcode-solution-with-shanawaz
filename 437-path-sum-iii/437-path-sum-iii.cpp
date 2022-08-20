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
  
    void countPathSum(TreeNode* root, int target, long sum,unordered_map<long long int,long long int>&mp,long long int &count){
        if(!root)
            return;
        sum += root->val;        //Path sum from root
        if(sum == target)
            count++;
        if(mp.find(sum - target) != mp.end())     
            count += mp[sum - target];
        mp[sum]++;
        countPathSum(root->left, target, sum,mp,count);
        countPathSum(root->right, target, sum,mp,count);
        mp[sum]--;      //After visiting the left and right subtree, we have to reduce this path sum count from map since we are leaving this path
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long int,long long int>mp;
        long long int count=0;
        countPathSum(root, targetSum, 0,mp,count);
        return count;
    }
};