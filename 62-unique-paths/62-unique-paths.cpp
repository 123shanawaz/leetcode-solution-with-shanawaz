class Solution {
public:
    int path(int m,int n,int i,int j,unordered_map<string,int>&mp){
        if(i>=m||j>=n){
            return 0;
        }
        if(i==m-1&&j==n-1){
            return 1;
        }
        string currentkey=to_string(i)+"_"+to_string(j);
        if(mp.find(currentkey)!=mp.end()){
            return mp[currentkey];
        }
        int right=path(m,n,i,j+1,mp);
        int left=path(m,n,i+1,j,mp);
        mp[currentkey]= right+left;
        return mp[currentkey];
        
    }
    int uniquePaths(int m, int n) {
        unordered_map<string,int>mp;
        return path(m,n,0,0,mp);
        
    }
};