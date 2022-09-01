class Solution {
public:
    int fib(int n) {
        unordered_map<int,int>mp;
        return fibonacci(n,mp);
    }
    private: int fibonacci(int n,unordered_map<int,int>&mp){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int currkey=n;
        if(mp.find(currkey)!=mp.end()){
            return mp[currkey];
        }
        int one=fibonacci(n-1,mp);
        int two=fibonacci(n-2,mp);
        mp[currkey]= one+two;
        return mp[currkey];
    }
};