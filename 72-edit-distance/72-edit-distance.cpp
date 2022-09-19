class Solution {
public:
    int minDistance(string word1, string word2) {
         int n=word1.size();
        int m=word2.size();
        unordered_map<string,int>mp;
       return solve(word1,word2,0,0,n,m,mp);
    }
    private:int solve(string &s, string &t,int i,int j,int n,int m, unordered_map<string,int>&mp){
        if(i>=n){
            return m-j;
        }
        if(j>=m){
            return n-i;
        }
        string currkey=to_string(i)+"_"+to_string(j);
        if(mp.find(currkey)!=mp.end()){
            return mp[currkey];
        }
        int ans=INT_MAX;
        if(s[i]==t[j]){
            ans=solve(s,t,i+1,j+1,n,m,mp);
        }
        else{
            int insert=1+solve(s,t,i,j+1,n,m,mp);
            int delt=1+solve(s,t,i+1,j,n,m,mp);
            int replace=1+solve(s,t,i+1,j+1,n,m,mp);
            ans=min(insert,(min(delt,replace)));
        }
        mp[currkey]= ans;
        return mp[currkey];
    }
};
