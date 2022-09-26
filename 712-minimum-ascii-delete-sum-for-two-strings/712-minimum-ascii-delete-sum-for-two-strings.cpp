class Solution {
public:
    int dp[1001][1001];
    int solve(string &s1, string &s2, int x, int y){
        if(x==s1.size() or y==s2.size()){
            int sum = 0;
            for(int i=x;i<s1.size();++i) sum+=int(s1[i]);
            for(int i=y;i<s2.size();++i) sum+=int(s2[i]);
            return sum;
        }
        
        if(dp[x][y]!=-1) return dp[x][y];
        //if both charater are same
        if(s1[x]==s2[y]) return solve(s1,s2,x+1,y+1);
        //if both charater are not same
        int asc1 = int(s1[x]) + solve(s1,s2,x+1,y);
        int asc2 = int(s2[y]) + solve(s1,s2,x,y+1);
        return dp[x][y] = min(asc1,asc2);
    }
    
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,0,0);
    }
};