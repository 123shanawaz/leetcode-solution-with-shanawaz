// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int mostBalloons(int N, pair<int, int> arr[]) {
        // Code here
       
        int ans=0;
        for(int i=0;i<N;i++){
            int x1=arr[i].first;
            int y1=arr[i].second;
             unordered_map<double,int>mp;
        int count=0;
            for(int j=0;j<N;j++){
                int x2=arr[j].first;
                int y2=arr[j].second;
                if(x1==x2 && y1==y2){
                    count++;
                    continue;
                }
                double n=(double)(y2-y1);
                double d=(double)(x2-x1);
                double slope=n/d;
                mp[slope]++;
                
                
            }
            for(auto &x:mp){
                ans=max(ans,(x.second+count));
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        pair<int, int> arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> arr[i].second;
        }
        Solution ob;
        cout << ob.mostBalloons(N, arr) << endl;
    }
}  // } Driver Code Ends