class Solution {
public:
     int diffcoin(vector<int>& coins,int currentidx, int amount,unordered_map<string,int>&mp){
        if(amount==0){
            return 1;
        }
        if(currentidx>=coins.size()){
            return 0;
        }
         string currentkey=to_string(currentidx)+"_"+ to_string(amount);
         if(mp.find(currentkey)!=mp.end()){
             return mp[currentkey];
         }
        
        int pic= 0;
        if(coins[currentidx]<=amount){
            pic=diffcoin(coins,currentidx,amount-coins[currentidx],mp);
        }
        int notpic=diffcoin(coins,currentidx+1,amount,mp);
        mp[currentkey]= (pic+notpic);
         return mp[currentkey];
    }
    int change(int amount, vector<int>& coins) {
        unordered_map<string,int>mp;
        int ans=diffcoin(coins,0,amount,mp);
        return ans;
    }
};