class Solution {
public:
   double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(101,vector<double>(101,0));
        dp[0][0]=poured;
        for(int i=0;i<100;i++){
            for(int j=0;j<=i;j++){
                if(dp[i][j]>1){
                    double rem=(dp[i][j]-1)/2;
                    dp[i+1][j] += rem;
                    dp[i+1][j+1] += rem;
                    dp[i][j]=1;
                }
            }
        }
        return dp[query_row][query_glass];
    }
};