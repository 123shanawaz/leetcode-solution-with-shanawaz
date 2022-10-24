class Solution {
    int fn(int i , vector<string> & arr, vector<int> &mp){
        if(i == arr.size()) return 0;
        
        int notTake = fn(i+1,arr,mp);
        
        int take = 0;
        vector<int> tmp(26);
        for(char c : arr[i]){
            if(tmp[c-'a'] != 0 || mp[c-'a'] != 0) return notTake;
            tmp[c-'a']++;
        }
        for(char c : arr[i]) mp[c-'a']++;
        take = arr[i].size() + fn(i+1,arr,mp);
        for(char c : arr[i]) mp[c-'a']--;
        return max(take,notTake);
        
    }
public:
    int maxLength(vector<string>& arr) {
        vector<int> mp (26,0);
        return fn(0,arr,mp);
    }
};