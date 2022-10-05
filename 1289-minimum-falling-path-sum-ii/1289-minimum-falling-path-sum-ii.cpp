class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // unordered_map<string,int>mp;
        vector<vector<int>>mp(n+1,vector<int>(m+1,-1));
        int ans=100001;
        for(int i=0;i<n;i++){
            ans=min(ans,solve(grid,0,i,n,m,mp));
        }
        return ans;
    }
    private:int solve(vector<vector<int>>& grid,int r,int c,int n,int m, vector<vector<int>>&mp){
        if(r==n-1){
            return grid[r][c];
        }
        // string currkey=to_string(r)+"_"+to_string(c);
        // if(mp.find(currkey)!=mp.end()){
        //     return mp[currkey];
        // }
        if(mp[r][c]!=-1){
            return mp[r][c];
        }
        int res=INT_MAX;
        for(int i=0;i<n;i++){
            if(i!=c){
           int tempAns=grid[r][c]+solve(grid,r+1,i,n,m,mp);
            res=min(tempAns,res);
            }
        }
        mp[r][c]=res;
        return mp[r][c];
    }
};