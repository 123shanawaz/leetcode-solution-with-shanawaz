class Solution {
public:
    int mod = 1000000007;
    
    long long solve(int p, int d, vector<vector<long long>> &dp){
        if(p==0 && d==0){
            return 1;
        }
        if(p < 0 || d < 0) return 0;
        
        if(dp[p][d] != -1) return dp[p][d];
        
        //for pickup: we have p choices to use as of now
        //for deliver: we have d-p choices to use as of now
        
        int k = ((p*(solve(p-1, d, dp)%mod))%mod  + ((d-p)*(solve(p, d-1, dp)%mod))%mod)%mod;
        return dp[p][d] = k%mod;
    }
    
    int countOrders(int n) {
        vector<vector<long long>> dp(n+1, vector<long long>(n+1, -1));
        int x = solve(n, n, dp);
        return x;
    }
};