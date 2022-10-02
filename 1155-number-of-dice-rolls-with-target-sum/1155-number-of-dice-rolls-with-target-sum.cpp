class Solution {
public:
    
    int MOD = 1e9+7;
    
    int f(int k, int n, int num, int target, int cur, vector<vector<int>> &dp){
        
        if(n==num and target!=cur) return 0;
        
        if(n==num and target==cur) return 1;
        
        if(dp[cur][num]!=-1) return dp[cur][num];
        
        long long total = 0;
        
        for(int i=1;i<=k;i++){
            
            total+=f(k, n, num+1, target, cur+i, dp);
            
        }
        
        return dp[cur][num]=total%MOD;
        
    }
    
    
    int numRollsToTarget(int n, int k, int target) {
        
		//initializing a dp array
        vector<vector<int>> dp(1001, vector<int> (n+1, -1));
        return f(k, n, 0, target, 0, dp);
        
    }
};