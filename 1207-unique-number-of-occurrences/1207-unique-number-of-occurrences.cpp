class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        set<int>s;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto a:mp){
            s.insert(a.second);
        }
        return mp.size()==s.size();
    }
};