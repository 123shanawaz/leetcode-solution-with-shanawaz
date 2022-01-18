class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int count=0;
        while(target>1){
             if(maxDoubles==0){
                    count+=(target-1);
                 break;
                }
            else if(target%2==0 ){
                count++;
                target/=2;
                maxDoubles--;
            
              
            }
            else{
                
                 count++;
                target-=1;
            }
        
        }
        return count;
    
        
    }
};