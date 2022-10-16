class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
          int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                    
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
       int ans=0;
        
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int step=q.front().second;
            q.pop();
            dist[row][col]=step;
       
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n &&  ncol>=0 && ncol<m && vis[nrow][ncol]==0 ){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},step+1});
                   
                }
            }
        }
         // int ans=0;
       for(int i=0;i<n;i++){
          
           for(int j=0;j<m;j++){
               ans=max(ans,dist[i][j]);
           }
       }
        if(ans==0){
            return -1;
        }
        return ans;
       
      
    }
};