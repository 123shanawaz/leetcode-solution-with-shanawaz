class Solution {
public:
    static bool compare(string s1, string s2)
    {
        return s1.size()<s2.size();
    }
    
    int longestStrChain(vector<string>& words) 
    {
        unordered_map<string, int> dp; //it stores predecessor word and chain size
        
        //sort(words.begin(), words.end(), [](const string &s1, const string &s2){ return s1.length()<s2.length();});
        sort(words.begin(), words.end(), compare);
        
        int len = 1; 
        for(auto word:words) 
        {
            dp[word]=1; 
            for(int i=0; i<word.length(); i++) 
            {
                //removing ith alphabet from the string and check remaining string is available in the dp 
                string pred = word.substr(0,i) + word.substr(i+1); 
                
                if(dp.find(pred) != dp.end()) 
                {
                    dp[word] = dp[pred]+1; 
                    len = max(len, dp[word]);
                }
            }
        }
        return len;    
    }
};