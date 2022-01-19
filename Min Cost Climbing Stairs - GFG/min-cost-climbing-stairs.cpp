// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  int mincost(vector<int>&cost ,int N,int idx,unordered_map<int,int>&mp){
      if(idx==N){
          return 0;
      }
      if(idx>N){
          return 100001;
      }
      int currentkey=idx;
      if(mp.find(currentkey)!=mp.end()){
          return mp[currentkey];
      }
      int onejump=mincost(cost,N,idx+1,mp);
      int twojump=mincost(cost,N,idx+2,mp);
      mp[currentkey]=min(onejump,twojump)+cost[idx];
      return mp[currentkey];
  }
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        unordered_map<int,int>mp;
         int a=mincost(cost,N,0,mp);
        int b=mincost(cost,N,1,mp);
        return min(a,b);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends