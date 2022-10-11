class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans=max(ans,dfs(grid,i,j,n,m));
                }
            }
        }
        return ans;
        
    }
    private:int dfs(vector<vector<int>>& grid,int i,int j,int n,int m){
        if(i<0 ||j<0||i>=n||j>=m||grid[i][j]==0){
            return 0;
        }
        grid[i][j]=0;
        int count=1;
        count+=dfs(grid,i-1,j,n,m);
        count+=dfs(grid,i+1,j,n,m);
        count+=dfs(grid,i,j-1,n,m);
        count+=dfs(grid,i,j+1,n,m);
        return count;
    }
};