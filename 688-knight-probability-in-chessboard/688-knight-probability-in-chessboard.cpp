class Solution {
public:
    double dp[101][27][27];
    double knight(int n, int k, int row, int column){
      
        // when we are getting out of the boundary, we can't get any answer, return 0
        if(row<0 || column<0 || row>=n || column>=n)
            return 0;
        
        // here we have to take exactly k moves, so when k==0, that means we got our destination
        // return 1
        if(k <= 0)
            return 1;
        if(dp[k][row][column]){
            
            return dp[k][row][column];
        }
        
        
        double sum = 0;
        
        // here the 8 directions where a knight can move
        // don't forget to moves -1 everytime
        sum = knight(n, k-1, row-2, column-1) +
              knight(n, k-1, row-2, column+1) +
              knight(n, k-1, row-1, column+2) +
              knight(n, k-1, row+1, column+2) +
              knight(n, k-1, row+2, column+1) +
              knight(n, k-1, row+2, column-1) +
              knight(n, k-1, row+1, column-2) +
              knight(n, k-1, row-1, column-2);
        // now calculate the avarage
        sum /= 8;
        
    
        return dp[k][row][column]=sum;
    }
    double knightProbability(int n, int k, int row, int column) {
        
         return knight(n, k, row, column);
    }
};

