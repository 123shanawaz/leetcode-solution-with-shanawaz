class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
          queue<string>q ;
    
    q.push(start) ;
    
    unordered_set<string>visited  ;
    int level = 0 ;
    
    while(!q.empty())
    {
       
        int n = q.size() ;
        
        for( int i = 0 ; i < n ; i++ )
        {
            string node = q.front() ;
            q.pop() ;
            
            if( node == end ) return level ;
            
            for( auto ch : "ACGT" )
            {
                
                for( int  j = 0 ; j < node.size() ; j++ )
                {
                    string adj = node ;
                    adj[j] = ch ;
                    if( visited.find(adj) == visited.end() && find( bank.begin()  , bank.end() , adj ) != bank.end() )
                    {
                        q.push(adj)  ;
                    visited.insert(adj) ;
                    }
                }
            }
            
        }
        
        level++ ;
    }
    
    return -1 ;
}
    
};