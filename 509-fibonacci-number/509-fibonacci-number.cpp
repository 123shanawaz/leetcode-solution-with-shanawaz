class Solution {
public:
  
    int find_fibonacci(int n,unordered_map<int,int> &mp){
       
        if(n==0)  return 0;
        if(n==1)  return 1;
        int currentkey = n;
        if(mp.find(currentkey)!=mp.end()){
          return mp[currentkey];
        }
        int ans1 = find_fibonacci(n-1,mp);
        int ans2 = find_fibonacci(n-2,mp);
        mp[currentkey] = ans1+ans2;
        return mp[currentkey];
        
    }
    int fib(int n) {
        unordered_map<int,int> mp;
        return find_fibonacci(n,mp);
    }
};
