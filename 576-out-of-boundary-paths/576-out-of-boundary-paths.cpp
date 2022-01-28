class Solution {
public:
    int dp[51][51][51];
    int mod = 1e9+7;
    int totalways(int m, int n, int maxMove, int startRow, int startColumn) {
      
        // when we are getting out of the boundary, we are getting one of answers,so return 1
        if(startRow > m-1 || startRow < 0 || startColumn > n-1 || startColumn < 0){
          return 1;
        }
        // when the number of moves became 0, we can't do anyhting , we don't have any step to 
        // move further, out of the bound , so return 0
        if(maxMove<=0) return 0;
      if(dp[maxMove][startRow][startColumn]!=-1){
          return dp[maxMove][startRow][startColumn];
      }
        // we can move 4 side right,left,up,down
        // right = row,col+1 , left = row,col-1 , up = row-1,col , down = row+1,col
        // everytime decrease the number of total moves
        long long int right = totalways(m,n,maxMove-1,startRow,startColumn+1)%mod;
        long long int left = totalways(m,n,maxMove-1,startRow,startColumn-1)%mod;
        long long int up = totalways(m,n,maxMove-1,startRow-1,startColumn)%mod;
        long long int down = totalways(m,n,maxMove-1,startRow+1,startColumn)%mod;
      
        // we have to return total ways, so add all possible 4 paths
        dp[maxMove][startRow][startColumn]= (right+left+up+down)%mod;
        return dp[maxMove][startRow][startColumn];
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return totalways(m,n,maxMove,startRow,startColumn)%mod;
    }
};
