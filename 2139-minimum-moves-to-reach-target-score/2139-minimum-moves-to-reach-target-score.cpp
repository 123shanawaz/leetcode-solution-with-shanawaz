class Solution {
public:
    int minMoves(int target, int maxDoubles) {
     int ans=0;
        while(target!=1 && maxDoubles!=0){
            if(target%2)
                ans++, target--;
               
                 else  target/=2,ans++,maxDoubles--;
            

        }
        ans+=(target-1);
        return ans;
    }
};