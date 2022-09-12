class Solution {
public:
	int f(int i,int sum,vector<vector<int>>& dp){
		if(i==1) return 1; 
		if(dp[i][sum]!=-1) return dp[i][sum];
		int notpick=f(i-1,sum,dp);
		int pick=0;
		if(sum>=i) pick=i*f(i,sum-i,dp);
		return dp[i][sum]=max(pick,notpick);
	}

	int integerBreak(int n){
		vector<vector<int>> dp(n,vector<int>(n+1,-1));
		return f(n-1,n,dp);
	}
}; 