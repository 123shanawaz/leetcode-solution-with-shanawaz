class RandomizedSet {
public:
    vector<int>v;
    unordered_map<int,int>mymap;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mymap.find(val)!=mymap.end()){
            return false;
        }
        v.push_back(val);
        mymap[val]=v.size()-1;
        return true;
        
    }
    
    bool remove(int val) {
        if(mymap.find(val)==mymap.end()){
            return false;
        }
        int last =v.back();
        mymap[last]=mymap[val];
        v[mymap[val]]=last;
        v.pop_back();
        mymap.erase(val);
        return true;
        
    }
    
    int getRandom() {
        return v[rand()%v.size()];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */