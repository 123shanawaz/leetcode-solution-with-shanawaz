//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:bool dfs(int node,vector<int> adj[],int vis[],int path[],int check[]){
        vis[node]=1;
        path[node]=1;
        check[node]=0;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,path,check)==true) {
                    check[node]=0;
                return true;
                }
            }
            else if(path[it]==1){
                check[node]=0;
                return true;
            }
           
        } 
         check[node]=1;
            path[node]=0;
            return false;
        
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
       int vis[V]={0};
       int path[V]={0};
       int check[V]={0};
        vector<int>ans;
       for(int i=0;i<V;i++){
           if(!vis[i]){
               dfs(i,adj,vis,path,check);
           }
       }
       for(int i=0;i<V;i++){
           if(check[i]==1){
               ans.push_back(i);
           }
       }
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends