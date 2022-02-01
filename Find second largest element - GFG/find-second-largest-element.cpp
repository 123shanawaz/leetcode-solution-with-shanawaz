// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
   public:
    int print2largest(int arr[], int arr_size)
    {
    	int i, first, second;
 
    /* There should be atleast two elements */
    if (arr_size < 2) {
       
        return -1;
    }
 
    first = second = INT_MIN;
    for (i = 0; i < arr_size; i++) {
        
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        }
 
       
        else if (arr[i] > second && arr[i] != first)
            second = arr[i];
    }
    if (second==INT_MIN)
    return -1;
    else
    return second;
    }
    

};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	    Solution ob;  
	    int ans=ob.print2largest(arr, n);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}
  // } Driver Code Ends