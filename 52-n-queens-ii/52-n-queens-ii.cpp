class Solution {
public:

//create ans vector to store all possible solutions
vector<vector<string>>ans;

//check whether other queen is present in column or not
bool issafe(int r,int c,vector<string>&v,int n){
    for(int i=0;i<=r;i++){
        //if present return false
        if(v[i][c]=='Q') return false;
    }
//check whether other queen is present in diagonally upper left position or not
    int row=r,col=c;
    while(row>=0&&col>=0){
     
        if(v[row][col]=='Q') return false;
        row--;col--;
    }
    //check whether other queen is present in diagonally upper right position or not
    row=r;col=c;
    while(row>=0&&c<n){
        if(v[row][col]=='Q') return false;
        row--;col++;
    }
    return true;
    //if no the queen is present in column and diagonally upper left and diagonally upper right positions return true(or is safe)
}

void solve(int r,vector<string>&v,int n){
    if(r==n){   
        ans.push_back(v);
        return;
    }
    //now fix the row and move over the column and check for safe position
    for(int i=0;i<n;i++){
        if(issafe(r,i,v,n)){
            v[r][i]='Q';
            solve(r+1,v,n); 
            v[r][i]='.';
        }
    }
}

int totalNQueens(int n) {
    //we required a board of size n*n to store n number of queens
    
    vector<string>v(n,string (n,'.'));
    // create a board with all non queen index
    solve(0,v,n); 
    // to palce n number of queens on there safe position call solve() function with row 0 
    
    return ans.size();
}
};