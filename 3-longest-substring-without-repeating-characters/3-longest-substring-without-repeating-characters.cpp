class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        int ans=0;
        unordered_map<char,int>mp;
        while(right<s.size()){
            char c=s[right];
                mp[c]++;
            
            while(mp[c]>1){
                char d=s[left];
                left++;
                mp[d]--;
            }
            right++;
            ans=max(ans,right-left);
        }
        return ans;
        
    }
};