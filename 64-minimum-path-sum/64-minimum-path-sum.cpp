class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        unordered_map<string,int>mp;
       int  m = grid.size();
      int n = grid[0].size();
        return minpath(grid,m,n,0,0,mp);
    }
    private: int minpath(vector<vector<int>>& grid,int m,int n,int row,int col,unordered_map<string,int>&mp){
        if(row>=m||col>=n ){
            return 1001;
        }
        if(row==m-1&& col==n-1){
            return grid[row][col];
        }
        string currkey=to_string(row)+"_"+to_string(col);
        if(mp.find(currkey)!=mp.end()){
            return mp[currkey];
        }
        int right=minpath(grid,m,n,row+1,col,mp)+grid[row][col];
        int down=minpath(grid,m,n,row,col+1,mp)+grid[row][col];
        mp[currkey]=min(right,down);
        return mp[currkey];
    }
};