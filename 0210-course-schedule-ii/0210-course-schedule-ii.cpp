class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
  
        int V=numCourses;
        vector<int>adj[V];  //craeting the graph/adj list
        for(int i=0;i<prerequisites.size();++i){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
       vector<int>indegree(V,0); //creating indegree array as per Kahn's Algo
        for(int i=0;i<V;++i){
            for(auto it:adj[i]){
                indegree[it]++;   //incrementing indegrees for each one in array
            }
        }
        queue<int>q;//queue as per Kahn's algo
        vector<int>topo; // storing Topo sort 
        for(int i=0;i<V;++i){
            if(indegree[i]==0){
                q.push(i);    //if indegrre of any edge is zero push in queue
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){ //consider as removing edge from the grap :)
                indegree[it]--;   //decrement the indgrees after the nodeprocessed
                if(indegree[it]==0) q.push(it);
            }
        }
        if(topo.size()==V) return topo; //if it'sValid Topo Sort return 1
        else return {}; //else 0
    }
        
    
};