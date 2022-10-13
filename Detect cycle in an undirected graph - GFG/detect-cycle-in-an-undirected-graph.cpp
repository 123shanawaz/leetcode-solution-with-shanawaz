//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
       int vis[V]={0};
       for(int i=0;i<V;i++){
           if(!vis[i]){
             if(dedect(i,adj,vis))return true;
       }
       }
       return false;
    }
   private: bool dedect(int sourcenode,vector<int>adj[],int vis[]){
        vis[sourcenode]=1;
        queue<pair<int,int>>q;
        q.push({sourcenode,-1});
        // int it=q.front();
        while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto adjnode:adj[node]){
            if(!vis[adjnode]){
                vis[adjnode]=1;
                q.push({adjnode,node});
            }
            else if(adjnode!=parent){
                return true;
            }
        }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends