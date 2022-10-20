class Solution {
public:
    string intToRoman(int num) {
        
        string ans = "";
        
        unordered_map <int,string> umap;
        vector <int> vec = {1000,900,500,400,100,90,50,40,10,9,5,4,1,};
        
        umap[1] = "I";
        umap[4] = "IV";
        umap[5] = "V";
        umap[9] = "IX";
        umap[10] = "X";
        umap[40] = "XL";
        umap[50] = "L";
        umap[90] = "XC";
        umap[100] = "C";
        umap[400] = "CD";
        umap[500] = "D";
        umap[900] = "CM";
        umap[1000] = "M";
        
        while(num>=1){
            int ind = 0;
            while(ind<13 && vec[ind]>num){
                ind++;
            }
            ans = ans + umap[vec[ind]];
            num = num - vec[ind];
        }
        
        return ans;
    }
};