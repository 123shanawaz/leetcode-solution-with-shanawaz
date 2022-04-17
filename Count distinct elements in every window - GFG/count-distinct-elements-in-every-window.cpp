// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        vector<int> vec;
       map<int, int>mp;
       
      // if(k>n) return vec;
       
       for(int i=0; i<k ; i++)
        {
            mp[A[i]]++;
        }
        vec.push_back(mp.size());
        
       for(int i=k; i<n ; i++)
       {
           if(mp[A[i-k]]==1) mp.erase(A[i-k]);
           else
            mp[A[i-k]]--;
           mp[A[i]]++; 
            
           vec.push_back(mp.size());
           
       }
        
        return vec;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends