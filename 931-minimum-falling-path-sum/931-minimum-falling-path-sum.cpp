class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        unordered_map<string,int>dp;
        int res=10000001;
        for(int i=0;i<n;i++){
            res=min(res,solve(matrix,0,i,dp));
        }
        return res;
        
    }
    private:int solve(vector<vector<int>>& matrix,int i, int j , unordered_map<string,int>&dp){
        if(j<0 || j>=matrix[0].size())
            return 1e9;
        
        if(i==matrix.size()-1)
            return matrix[i][j];
			
        string currkey=to_string(i)+"_"+to_string(j);
        if(dp.find(currkey)!=dp.end()){
            return dp[currkey];
        }
        int a = matrix[i][j] + solve(matrix,i+1,j,dp);
        int b = matrix[i][j] + solve(matrix,i+1,j+1,dp);
        int c = matrix[i][j] + solve(matrix,i+1,j-1,dp);
        
        dp[currkey]=min(a,min(b,c));
        return dp[currkey];
    }
};