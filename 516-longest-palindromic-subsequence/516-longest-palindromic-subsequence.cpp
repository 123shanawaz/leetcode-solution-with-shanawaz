class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
          int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        return solve(s,t,n-1,m-1,dp);
        
        
    }
     private:int solve(string &text1, string &text2,int i,int j, vector<vector<int>>&dp){
        if(i<0 ||j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(text1[i]==text2[j]){
            return dp[i][j]= 1+solve(text1,text2,i-1,j-1,dp);
        }
        else{
             int a=solve(text1,text2,i-1,j,dp);
                 int b=solve(text1,text2,i,j-1,dp);
            return dp[i][j]=max(a,b);
        }
       
    }
};