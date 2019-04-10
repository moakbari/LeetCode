class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < words.size() - 1; i++){
            bool breakBeforeEnd = false;
            for(int j = 0; j < min(words[i].size(), words[i+1].size()); j++){
                
                if (words[i][j] == words[i+1][j]){
                    continue;
                }
                
                if (order.find(words[i][j]) < order.find(words[i+1][j])){
                    breakBeforeEnd = true;
                    break;
                }else {
                    return false;
                }
            }
            
            if (!breakBeforeEnd && words[i].size() > words[i+1].size()){
                return false;
            }
        }
        
        return true;
    }
};
