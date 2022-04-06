class Solution {
public:
    long long int binarysearch(int n){
        int s=0;
        int e=n;
        int ans=-1;
        while(s<=e){
            long long int mid=s+(e-s)/2;
            if(mid*mid==n){
                return mid;
            }
            if(mid*mid<n){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
        
    }
    
    int mySqrt(int x) {
        return binarysearch(x);
    }
};