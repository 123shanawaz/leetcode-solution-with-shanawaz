class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
            return false;
        int n=s2.size();
    unordered_map<char,int>mp;
        for(int i=0;i<s1.size();i++)
        {
            mp[s1[i]]++;
        }
        int  count=mp.size(),i=0,j=0;
        int window_size=s1.size();
        while(j<n)
        {
            if(mp.find(s2[j])!=mp.end())
            {
                mp[s2[j]]--;
                if(mp[s2[j]]==0)
                    count--;
            }
            
            if(j-i+1<window_size)
                j++;
            else if(j-i+1==window_size)
            {
                if(count==0)
                {
                    return true;
                }
                if(mp.find(s2[i])!=mp.end())
                {
                    mp[s2[i]]++;
                    if(mp[s2[i]]==1)
                        count++;
                }
                i++;
                j++;
            }
        }
        return false;
    }
};