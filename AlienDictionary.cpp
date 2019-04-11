class Solution {
    bool doDFS(char c, unordered_map<char, unordered_set<char>>& charRelation, unordered_set<char>& curPath, stack<char>& orderedChars, unordered_set<char>& processed)
    {
        if (curPath.count(c)){
            return false;
        }
        
        if (processed.count(c)){
            return true;
        }
        
        curPath.emplace(c);
        
        if (charRelation.find(c) != charRelation.end()){
            unordered_set<char> children = charRelation[c];
            for(unordered_set<char>::const_iterator iter = children.begin();
            iter != children.end(); iter++){
                if(doDFS(*iter, charRelation, curPath, orderedChars, processed) == false){
                        return false;
                }
            }
        }
        
        processed.emplace(c);
        orderedChars.push(c);
        return true;
    }
public:
    string alienOrder(vector<string>& words) {
        unordered_set<char> charSet; // set containing all the letters
        unordered_map<char, unordered_set<char>> charRelation; // graph where each letter is a node
        
        
        for_each(words.begin(), words.end(), [&charSet](const string& w){
            for_each(w.begin(), w.end(), [&charSet](const char& c){
                charSet.emplace(c);
            }); 
        });
        
        // create a directed graph based on ordering of the letters
        for (int i = 0; i < words.size()  - 1; i++){
            for(int j = 0; j < min(words[i].size(), words[i+1].size()); j++){
                if (words[i][j] != words[i+1][j]){
                    charRelation[words[i][j]].emplace(words[i+1][j]);             
                    break;
                }
            }
        }
        
        // find topological ordering of the letters
        stack<char> orderedChars;
        unordered_set<char> processed;
        for (unordered_set<char>::const_iterator iter = charSet.begin();
            iter != charSet.end(); iter++){
            if(processed.count(*iter) == 0){
                unordered_set<char> curPath;
                if(doDFS(*iter, charRelation, curPath, orderedChars, processed) == false){
                    return "";
                }
            }
        }
        
        string result;
        while(!orderedChars.empty()){
            result.push_back(orderedChars.top());
            orderedChars.pop();
        }
        
        return result;
    }
};
