// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int cuttrod(int price[],int n,int currentidx,unordered_map<string,int>&mp){
      if(n==0){
          return 0;
      }
      if(currentidx>=n){
          return 0;
      }
      string currentkey=to_string(currentidx)+"_"+to_string(n);
      if(mp.find(currentkey)!=mp.end()){
          return mp[currentkey];
      }
      int cut=0;
      if(currentidx+1<=n){
          cut=price[currentidx]+cuttrod(price,n-(currentidx+1),currentidx,mp);
      }
      int notcut=cuttrod(price,n,currentidx+1,mp);
      mp[currentkey]= max(cut,notcut);
      return mp[currentkey];
  }
    int cutRod(int price[], int n) {
        unordered_map<string,int>mp;
        return cuttrod(price,n,0,mp);
    
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends