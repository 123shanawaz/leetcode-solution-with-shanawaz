class Solution {
public:
    int minDeletions(string s) 
    {
        unordered_map<char,int> m;                                // map to store freq
        for(auto e:s)
        {
            m[e]++;
        }
        vector<int> v;                                                                  // same store in vector
        for(auto e:m)
        {
            v.push_back(e.second);
        }
        sort(v.begin(),v.end());                                                   // sort to figure out same element (freq)
//         for(auto e:v)
//         {
//             cout<<e<<" ";                                                         // print vector
//         }
        // cout<<endl; 
        int count=0;                                                                       // maintain  count for no. of operation
        bool check=1,maincheck=1;                    // maincheck check the condition that while loop or not (not means all freq are different)
        while(maincheck)
        {
            for(int i=1;i<v.size();i++)
            {
                if(v[i]==v[i-1] && v[i]!=0 && v[i-1]!=0 )                              // check for equal freq  but not equal to 0,0
                {
                    count++;                                                                      // increment count need to delete
                    v[i-1]--;                                                                        // decrement freq for that element
                }
            }
            sort(v.begin(),v.end());                                                           // try to sort if v is unsorted but i guess no need 
//             for(auto e:v)
//         {
//             cout<<e<<" ";                                                                 // print vector just for what happen inside
//         }
//         cout<<endl;
            check=0;                                                                        // temp check for same freq
            for(int i=1;i<v.size();i++)
            {
                if(v[i]==v[i-1] && v[i]!=0 && v[i-1]!=0 )
                {
                    check=1;                                                                 // if yes then one more time while loop have to run
                    break;                                                                       // break out from that point it have to delete 
                }
            }
            if(check)
            {
                maincheck=1;                                                        // maincheck must =1 to run while loop again and skip and go for run while loop
                continue;
            }
            maincheck=0;                                                             // if check=0 means no freq equal or ( all different)
        }
        return count;                                                                   // just return count
    }
};