class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
        
        
    }
    private:int solve(int n , vector<int>&dp){
        if(n==1 || n==0){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int way=0;
        for(int i=0;i<n;i++){
            way+=solve(i,dp)*solve(n-i-1,dp);
        }
        dp[n]= way;
        return dp[n];
    }
};