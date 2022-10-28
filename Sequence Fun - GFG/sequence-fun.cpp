//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
	public:
		  int NthTerm(int n){
		    // Code  here
		    long long answer=1;
		    long mod=1000000007;
		    for(int i=1;i<=n;i++){
		        answer=((answer*i)+1)%mod;
		    }
		    return (int)answer;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends