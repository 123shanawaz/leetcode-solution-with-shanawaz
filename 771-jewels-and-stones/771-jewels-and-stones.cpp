class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
       int count=0;
        unordered_map<char,int>mp;
       for(auto i:jewels){
           mp[i]++;
       }
        for(auto j:stones){
            if(mp.find(j)!=mp.end())
                count++;
        }
        return count++;
    }
};