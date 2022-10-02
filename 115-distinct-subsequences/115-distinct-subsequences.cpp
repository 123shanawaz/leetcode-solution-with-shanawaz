class Solution {
public:
    int mod=(int)(1e9+7);
    int numDistinct(string s, string t) {
        int m=s.size(),n=t.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        for(int i=0;i<=m;++i)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return (int)dp[m][n];
    }
};