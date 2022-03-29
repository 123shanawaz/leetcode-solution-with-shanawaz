class Solution {
public:
    void floodFiller(vector<vector<int>>& image, int i, int j, int m,int n,int currcolor,int newColor){
       
        if(i<0||i>=m||j<0|j>=n||image[i][j]==newColor||image[i][j]!=currcolor){
            return;
        }
        image[i][j]=newColor;
        floodFiller(image,i-1,j,m,n,currcolor,newColor);
        floodFiller(image,i+1,j,m,n,currcolor,newColor);
        floodFiller(image,i,j+1,m,n,currcolor,newColor);
         floodFiller(image,i,j-1,m,n,currcolor,newColor);
        return;
            
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
         if(image[sr][sc]==newColor){
            return image;
        }
        int m=image.size();
        int n=image[0].size();
        int currcolor=image[sr][sc];
        floodFiller(image,sr,sc,m,n,currcolor,newColor);
        return image;
    }
    
};