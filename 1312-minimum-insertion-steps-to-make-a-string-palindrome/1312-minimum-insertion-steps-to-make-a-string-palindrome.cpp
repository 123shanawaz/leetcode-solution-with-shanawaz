class Solution {
public:
    int minInsertions(string s) {
  vector<vector<int>> mp(s.size(), vector<int>(s.size(), -1));
        
        int n=s.size();
        
        return minop(s,0,n-1,mp);
        
    }
    private:int minop(string &s,int i,int j,   vector<vector<int>> &mp){
        if(i>=j){
            return 0;
        }
        
        // string currkey=to_string(i)+"_"+to_string(j);
        int ans=1001;
        if(mp[i][j]!=-1){
            return mp[i][j];
        }
        if(s[i]==s[j]){
            ans= mp[i][j]= minop(s,i+1,j-1,mp);
        }
        else{
            int a=1+minop(s,i+1,j,mp);
            int b=1+minop(s,i,j-1,mp);
            mp[i][j]=min(ans,min(a,b));
           
        }
         return mp[i][j];
    }
};