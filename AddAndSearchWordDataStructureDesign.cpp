class WordDictionary {
    struct TrieNode{
        bool isEnd_;
        vector<TrieNode*> children_;
        
        TrieNode(bool isE)
        :isEnd_(isE)
        ,children_(26, NULL)
        {}
    };
    
    TrieNode* rootNode_;
    
    void addWordHelper(const string& word, int index, TrieNode* node){
        if (index == word.size()){
            node->isEnd_ = true;
            return;
        }
        
        if (!node->children_[word[index] - 'a']){
            node->children_[word[index] - 'a'] = new TrieNode(false);   
        }
        
        addWordHelper(word, index + 1, node->children_[word[index] - 'a']);
    }
    
    bool searchHelper(const string& word, int index, TrieNode* node){
        if (index == word.size() ){
            return node->isEnd_;
        }
        
        if (word[index] == '.'){
            for(int i = 0; i < node->children_.size(); i++){
                if (node->children_[i] && searchHelper(word, index + 1, node->children_[i])){
                    return true;                    
                }
            }
        }else{
            if (node->children_[word[index] - 'a'] && 
               searchHelper(word, index + 1, node->children_[word[index] - 'a'])){
                return true;
            }
        }
        
        return false;
    }
    
public:
    /** Initialize your data structure here. */
    WordDictionary() 
    :rootNode_(new TrieNode(false))
    {}
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        addWordHelper(word, 0, rootNode_);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchHelper(word, 0, rootNode_);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
