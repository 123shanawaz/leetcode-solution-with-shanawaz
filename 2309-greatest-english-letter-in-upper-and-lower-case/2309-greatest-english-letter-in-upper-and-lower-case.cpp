class Solution {
public:
    string greatestLetter(string s) {
        //store string in a hashmap for easy finding
        unordered_map<char, int> mpp;
        for(auto it: s){
            mpp[it]++;
        }
        
        sort(s.begin(), s.end());   //because we want greater value at the end
        string str = "";
        for(int i=0; i<s.size(); i++){
            
            char l = tolower(s[i]);
            char u = toupper(s[i]);
            // cout<<l<<" "<<u<<endl;
            
            if(mpp[l] && mpp[u]){   //if we have both lower and upper case for a letter
                str = u;
            }     
        }
        
        return str;
    }
};