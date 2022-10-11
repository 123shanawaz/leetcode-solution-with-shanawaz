class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
          int n= grid.size();
        int m= grid[0].size();
        
        
        /* 
        1. Iterate over the borders, and see if any island starts from the border itself.
        2. If starts from border(i.e. cell value is 0), find that island and change the cell values to 1 using DFS/BFS. 
        3. 2nd step will modify the grid and removes the possibility to get open (not closed) islands.
        4. Now, the problem is modified to find "Number of Islands (Leetcode #200)" using modified grid.
        */
    
       for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i*j==0||i==n-1||j==m-1){
                    if(grid[i][j]==0){
                        bfs(grid,i,j,n,m);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    ans++;
                    bfs(grid,i,j,n,m);
                }
            }
        }
        return ans;
        
    }
    
    
    
    //BFS approach
    private: void bfs(vector<vector<int>>& grid, int currRow, int currCol, int m, int n){
        queue<pair<int,int>>q;
        q.push({currRow, currCol});
        
        while(!q.empty()){
            //Pop from queue and verify if it's valid cell
            auto it=q.front();
            q.pop();
            
            int rowNumber= it.first;
            int colNumber= it.second;
            
            /*If valid cell, then:
                1. visit cell and mark it visited by changing the value to '1'
                2. add its neighbours to the queue */
            if(isValidCell(rowNumber, colNumber, m, n, grid)){
                grid[rowNumber][colNumber]= 1;
                
                q.push({rowNumber-1,colNumber}); //up
                q.push({rowNumber+1,colNumber}); //down
                q.push({rowNumber,colNumber-1}); //left
                q.push({rowNumber,colNumber+1}); //right
            }
        }
    
    }
    
    //method to check base condition
    private: bool isValidCell(int rowNumber,int colNumber, int m, int n, vector<vector<int>>& grid){
            if(rowNumber<0 || rowNumber>=m || colNumber<0 || colNumber>=n|| grid[rowNumber][colNumber]==1){
                return false;
       
    }
        return true;
}
    
};