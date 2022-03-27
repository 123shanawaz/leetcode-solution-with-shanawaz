class Solution {
public:
    
   void Dfs(vector<vector<int>>&graph,int currnode,vector<bool>vis,vector<int>&currentpath,vector<vector<int>>&ans, int n){
        if(currnode==n-1){
            ans.push_back(currentpath);
            return;
        }
//         if(vis[currnode]==true){
//             return;
//         }
        
//         vis[currnode]=true;
        for(auto it:graph[currnode]){
            currentpath.push_back(it);
            Dfs(graph,it,vis,currentpath,ans,n);
            currentpath.pop_back();
            
        }
       return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>ans;
        vector<int>currentpath;
        vector<bool>vis(n,false);
        currentpath.push_back(0);
      
        Dfs(graph,0,vis,currentpath,ans,n);
        return ans;
    }
};



