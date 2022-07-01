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
    vector<vector<int>> answer;
    void DFS_levelorder(TreeNode* root,int level) 
    {
        if(!root) return;  //if root is NULL then return
        if(level==answer.size())  //if level is equal to answer size then we have to push one empty element into it
            answer.push_back(vector<int> ());  //pushing extra element to accomodate next level nodes
        answer[level].push_back(root->val);  //pushing current node to the level index of answer
        DFS_levelorder(root->left,level+1);  //recursive call to traverse left subtree by increasing the level order
        DFS_levelorder(root->right,level+1);  //recursive call to traverse right subtree by increasing the level order
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        DFS_levelorder(root,0);  //calling function to traverse whole tree by passing root and level order
        return answer;  
    }
};