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
class Solution
{
public:
    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }
    int deepestLeavesSum(TreeNode *root)
    {
        int sum = 0;
        if (root == NULL)
        {
            return sum;
        }
        int last_level = height(root);
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();

            for (int i = 0; i < n; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (last_level == 1)
                {
                    sum += curr->val;
                }
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }

            last_level--;
        }
        return sum;
    }
};