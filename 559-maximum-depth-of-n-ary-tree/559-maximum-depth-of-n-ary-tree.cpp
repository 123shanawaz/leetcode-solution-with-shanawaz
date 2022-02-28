/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
         
        if(root==NULL)return 0;
        queue<Node*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            level+=1;
            int n=q.size();
            for(int i=0;i<n;i++){
            Node* currNode=q.front();
                q.pop();
           vector<Node*>v=currNode->children;
                for(auto i:v){
                    q.push(i);
                }
            }
            
        }
        return level;
    }
};