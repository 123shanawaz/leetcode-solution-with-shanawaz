class Solution {
public:
    
   void Dfs(vector<vector<int>>&graph,int currnode,vector<bool>vis,vector<int>&currentpath,vector<vector<int>>&ans, int n){
        if(currnode==n-1){
            ans.push_back(currentpath);
            return;
        }
        if(vis[currnode]==true){
            return;
        }
        
        vis[currnode]=true;
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


// class Solution
// {
//     public:
//         void sourceToTarget(vector<vector < int>> &graph, int currentNode, vector<bool>visited,int n, vector<int> &currentPath, vector< vector< int>> &answer)
//         {
//             if (currentNode == n - 1)
//             {
//                 answer.push_back(currentPath);
//                 return;
//             }

//             if (visited[currentNode] == true)
//             {
//                 return;
//             }

//             visited[currentNode] = true;


//             for (auto neighbour: graph[currentNode])
//             {
//                 currentPath.push_back(neighbour);
//                 sourceToTarget(graph, neighbour, visited, n, currentPath, answer);
//                 currentPath.pop_back();
//             }
//             // visited[currentNode] = false;
//             return;
//         }
//     vector<vector < int>> allPathsSourceTarget(vector<vector < int>> &graph)
//     {
//         vector<vector<int>> answer;
//         vector<int> currentPath;
//         int n = graph.size();
//         vector<bool> vis(n,false);
//         currentPath.push_back(0);
//         sourceToTarget(graph, 0, vis, n, currentPath, answer);
//         return answer;
//     }
// };

