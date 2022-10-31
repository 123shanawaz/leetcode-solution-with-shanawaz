//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
      vector<pair<int,int>>adj[n+1];
      for(auto e:edges){
          adj[e[0]].push_back({e[1],e[2]});
          adj[e[1]].push_back({e[0],e[2]});
      }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,1e9);
        vector<int>parent(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        dist[1]=0;
        pq.push({0,1});
        while(!pq.empty()){
        auto it=pq.top();
        int dis=it.first;
        int node=it.second;
        pq.pop();
        for(auto it:adj[node]){
            int adjnode=it.first;
            int edw=it.second;
            if(dis+edw<dist[adjnode]){
                dist[adjnode]=dis+edw;
                pq.push({dis+edw,adjnode});
                parent[adjnode]=node;
            }
        }
        }
        if(dist[n]==1e9) return {-1};
        vector<int>path;
        int node=n;
        while(parent[node]!=node){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends