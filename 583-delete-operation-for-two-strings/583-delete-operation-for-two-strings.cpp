class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        unordered_map<string,int>mp;
        return solve(word1,word2,n,m,0,0,mp);
        
        
    }
    private:int solve(string s1,string s2,int n,int m,int i,int j ,unordered_map<string,int>&mp){
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
        int ans=1000;
        if(s1[i]==s2[j]){
           mp[currkey]= ans=solve(s1,s2,n,m,i+1,j+1,mp);
        }
        else{
            int a=1+solve(s1,s2,n,m,i,j+1,mp);
            int b=1+solve(s1,s2,n,m,i+1,j,mp);
            mp[currkey]=min(ans,min(a,b));
        }
        return mp[currkey];
    }
};