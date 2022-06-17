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
    /*
    
    
    There are 4 possibility:
        covered     hasCamera
         yes           yes  (possible)  returns 0
         yes           no   (possible)  returns 1
         no            yes  (im-possible)  invalid state
         no             no  (possible)  returns -1
   
   There can be 3 return values for a node:
   1. If a child(root) needs a camera,It will tell to parent that you place a camera on you return -1,(in need of camera)
   
   2.  If a child has a camera it will return 0,
   
   3. I dont need camera  and neither I have camera return 1.
    
    
    */
    int populate(TreeNode* root,int &camera){
        
        if(root==NULL) return 1;
        
        // post order
        int left=populate(root->left,camera);
        int right=populate(root->right,camera);
        
        // We have to place camera on this node (parent), as childrens are not covered ...Thats why child has return  -1. 
		// If we do not place camera on this node, then its children will remain uncovered which is not acceptable.
        if(left==-1 || right==-1){
            ++camera;
            return 0;
        }
        
        // its one of the child has camera ,So need of camera on this node(parent) ,
        if(left==0 || right==0) return 1;
        
        // here left and right (both) are 1
        // means that neither of the child has camera but they are covered.
        // therfore, I will return -1 to parent to tell that I am not covered , place camera on you(parent) so that i(child) can get covered.
         else return -1;      
    }
    int minCameraCover(TreeNode* root) {
        int camera=0;      
        int x=populate(root,camera);
		// x=-1 means that even root is not covered So, it needs a camera
        if(x==-1) ++camera;
        return camera;
        
    }
};