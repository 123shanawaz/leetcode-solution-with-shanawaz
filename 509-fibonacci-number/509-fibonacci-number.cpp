class Solution {
public:
    int fib(int n) {
        return fibonacci(n);
    }
    private: int fibonacci(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int one=fibonacci(n-1);
        int two=fibonacci(n-2);
        return one+two;
    }
};