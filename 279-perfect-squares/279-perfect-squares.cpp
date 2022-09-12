class Solution {
public:
    int numSquares(int n) {
        unordered_map<int,int>mp;
	  return solve(n,mp);
        
    }
    private:int solve(int n,unordered_map<int,int>&mp){
         if(n==0){
	        return 0;
	    }
	    int currkey=n;
	    if(mp.find(currkey)!=mp.end()){
	        return mp[currkey];
	    }
	    int ans=INT_MAX;
	    for(int i=1;i*i<=n;i++){
	        ans=min(ans,1+solve(n-i*i,mp));
	    }
	    mp[currkey]=ans;
	    return mp[currkey];
	
    }
};