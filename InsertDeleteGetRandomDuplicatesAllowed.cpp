class RandomizedCollection {
    vector<int> numsCollection;
    unordered_map<int, unordered_set<int>> valToIndexMap;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool retVal = false;
        if(valToIndexMap.count(val) == 0){
            retVal = true;
        }
        
        numsCollection.push_back(val);
        valToIndexMap[val].emplace(numsCollection.size() - 1);
        return retVal;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        
        if(valToIndexMap.count(val) == 0){
            return false;
        }
   
        int valAtEnd = numsCollection.back();
        int index;
        if (valAtEnd != val){
            /* get the val's index in numsCollection*/
             index = *(valToIndexMap[val].begin());
            // we are going to swap last element in numsCollection with value at index
            // so remove last index from the list of appearing indeces of last element
            // and add index to that list
            valToIndexMap[valAtEnd].erase(numsCollection.size() - 1);
            valToIndexMap[valAtEnd].emplace(index);
            
            // swap and remove the element at index
            swap(numsCollection[index], numsCollection[numsCollection.size() - 1]);
        }else{
            index = numsCollection.size() - 1;
        }
        

        numsCollection.pop_back();
        
        //remove index from the list of indices where val appears
        valToIndexMap[val].erase(index);
        
        // clean up map if there is no more val left
        if (valToIndexMap[val].empty()){
            valToIndexMap.erase(valToIndexMap.find(val));  
        }
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int index = rand() % numsCollection.size();
        return numsCollection[index];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
