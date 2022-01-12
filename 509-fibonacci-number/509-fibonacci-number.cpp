class Solution {
public:
   int findfibonacci(int n){
        if(n==0)
            return 0;
        if(n==1) 
            return 1;
        
        int ans1=findfibonacci(n-1);
        int ans2=findfibonacci(n-2);
    return ans1+ans2;
   }
    int fib(int n) {
        return findfibonacci(n);
    }
};