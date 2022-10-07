class Solution {
public:
int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        
        vector<int>adj[n];
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]!=0){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>ans;
        int cnt=0;
        for(int i=0;i<n;i++){
            
            if(vis[i])continue;

           cnt++;
        
            vis[0]=1;

            queue<int>store;

            store.push(i); 

            vector<int>ans;

            while(!store.empty()){

                int node = store.front();

                store.pop();

                ans.push_back(node);

                for(auto it: adj[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        store.push(it);
                    }
                }
            }
        }
        return cnt;        
    }
};