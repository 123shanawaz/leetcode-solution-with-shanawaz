class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1){
            return -1;
        }
        if(grid[0][0]==0 && m==1 && n==1) return 1;
      
        vector<vector<int>> vis(n, vector<int>(m, 0));
           queue<pair<pair<int,int>,int>>q;
      q.push({{0,0},1});
         int arri[8] = {-1, -1, 0, +1, +1, +1, 0, -1};
        int arrj[8] = {0, +1, 1, 1, 0, -1, -1, -1};
      while(!q.empty()){
          int x=q.front().first.first;
        int y = q.front().first.second;
         int step=q.front().second;
            q.pop();
            
            for(int k=0; k<8; k++){
                int i = x + arri[k];
                int j = y + arrj[k];
                
                if(i>=0 && j>=0 && i<n && j<m && grid[i][j] == 0 && !vis[i][j]){
                  
                    q.push({{i, j},step+1});
                      vis[i][j] = 1;
                    if(i==n-1 && j==m-1){
                        return step+1;
                    }
                }
            }
        }
        return -1;
      
        
    }
        
    
};