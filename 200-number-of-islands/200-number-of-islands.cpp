class Solution {
public:
    int numIslands(vector<vector<char>>& grid) { 
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    solve(grid,n,m,i,j);
                }
            }
        }
        return count;
        
    }
    private:void solve(vector<vector<char>>& grid,int n,int m,int i,int j){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]=='0'){
    return ;
    }
        grid[i][j]='0';
        solve(grid,n,m,i-1,j);
        solve(grid,n,m,i+1,j);
        solve(grid,n,m,i,j+1);
        solve(grid,n,m,i,j-1);
        return;
}
};