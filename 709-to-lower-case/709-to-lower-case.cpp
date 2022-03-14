class Solution {
public:
    string toLowerCase(string s) {
        
     for(auto &x:s){
         if(x>='A' && x<='Z')
             x+=32;
     }  
        return s;
    }
};