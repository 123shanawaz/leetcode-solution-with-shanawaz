class Solution {
public:
    int maxpath(int m,int n,int i,int j,unordered_map<string,int>&mp){
        if(i>=m||j>=n){
            return 0;
        }
        if(i==m-1&&j==n-1){
            return 1;
        }
        string idx=to_string(i)+"_"+to_string(j);
        if(mp.find(idx)!=mp.end()){
            return mp[idx];
        }
        int row=maxpath(m,n,i+1,j,mp);
        int down=maxpath(m,n,i,j+1,mp);
        mp[idx]= row+down;
        return mp[idx];
    }
    int uniquePaths(int m, int n) {
        unordered_map<string,int>mp;
        return maxpath(m,n,0,0,mp);
        
    }
};