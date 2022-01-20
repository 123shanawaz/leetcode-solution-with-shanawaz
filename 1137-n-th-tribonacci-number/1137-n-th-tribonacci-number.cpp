class Solution {
public:
    int nthtribonacci(int n,unordered_map<int,int>&mp){
        if(n==0){
            return 0;
            
        }
        if(n==1 || n==2){
            return 1;
        }
        int currentkey=n;
        if(mp.find(currentkey)!=mp.end()){
            return mp[currentkey];
        }
        int a=nthtribonacci(n-1,mp);
        int b=nthtribonacci(n-2,mp);
        int c=nthtribonacci(n-3,mp);
        mp[currentkey]=a+b+c;
        return mp[currentkey];
    }
    
    int tribonacci(int n) {
        unordered_map<int,int>mp;
        return nthtribonacci(n,mp);
        
    }
};