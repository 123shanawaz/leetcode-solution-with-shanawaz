// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    
    int maxprofit(int W,int wt[],int val[],int n,int currentidx,unordered_map<string,int>&mp){
        if(currentidx>=n){
            return 0;
        }
        string currentkey=to_string(currentidx) +"_"+ to_string(W);
        if(mp.find(currentkey)!=mp.end()){
            return mp[currentkey];
        }
        int pick=0;
        if(wt[currentidx]<=W){
            pick=val[currentidx]+maxprofit(W-wt[currentidx],wt,val,n,currentidx+1,mp);
        }
        int notpick=maxprofit(W,wt,val,n,currentidx+1,mp);
        mp[currentkey]= max(pick,notpick);
        return mp[currentkey];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        unordered_map<string,int>mp;
       return maxprofit(W,wt,val,n,0,mp);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends