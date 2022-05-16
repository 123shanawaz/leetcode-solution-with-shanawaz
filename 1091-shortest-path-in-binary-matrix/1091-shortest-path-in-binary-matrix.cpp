class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1){
            return -1;
        }
        vector<vector<int>> visited(n, vector<int>(n, -1));
        visited[0][0] = 1;
        
        int arri[8] = {-1, -1, 0, +1, +1, +1, 0, -1};
        int arrj[8] = {0, +1, 1, 1, 0, -1, -1, -1};
        
        queue<pair<int, int>> q;
        q.push({0,0});
        
        while(!q.empty()){
            pair<int, int> temp = q.front(); q.pop();
            int x = temp.first;
            int y = temp.second;
            
            for(int k=0; k<8; k++){
                int i = x + arri[k];
                int j = y + arrj[k];
                
                if(i>=0 && j>=0 && i<n && j<n && grid[i][j] == 0 && visited[i][j] == -1){
                    visited[i][j] = visited[x][y] + 1;
                    q.push({i, j});
                }
            }
        }
        
        return visited[n-1][n-1];
        
    }
        
    
};