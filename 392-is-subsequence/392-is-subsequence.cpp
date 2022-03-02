class Solution {
public:
    bool isSubsequence(string s, string t) {
         int lenS = s.length(), lenT = t.length();
        int val=0;
        for(int i=0,j=0;i<lenT;i++){
            if(t[i] == s[j]){ 
                j++;
                val++;
            }
        }
        return val == lenS;
    
    }
};