class AllOne {
    using ListType = list<unordered_set<string>>;
    using ListIter = ListType::iterator;
    
    unordered_map<string, ListIter> keyMap;
    ListType bucketList;
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(keyMap.count(key) == 0){
            if(bucketList.empty()){
                bucketList.push_back(unordered_set<string>());
            }
            
            keyMap[key] = bucketList.begin();
        }else{
            if (keyMap[key] == prev(bucketList.end())){
                bucketList.push_back(unordered_set<string>());
            }
            
            ListIter curIter = keyMap[key];
            keyMap[key] = next(curIter);
            
            curIter->erase(key);
        }
        
        keyMap[key]->emplace(key);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (keyMap.count(key) == 0){
            return;
        }
        
        ListIter curIter = keyMap[key];
        curIter->erase(key);
        
        if(curIter == bucketList.begin()){
            keyMap.erase(key);
        }else{
            keyMap[key] = prev(curIter);
            keyMap[key]->emplace(key);
        }
 
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (keyMap.empty()){
            return "";   
        }
        
        ListIter iter = prev(bucketList.end());
        while(iter->empty()){
            iter = prev(iter);
        }
        
        return *(iter->begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (keyMap.empty()){
            return "";   
        }
        
        ListIter iter = bucketList.begin();
        while(iter->empty()){
            iter = next(iter);
        }
        return *(iter->begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
