class Solution {
    bool isValid(const string& s){
        int count = 0;
        
        for (const char& c : s){
            if (c == '('){
                count++;
            }else if ( c == ')'){
                count--;
                if (count < 0){
                    return false;
                }
            }else{
                continue;
            }
        }
        
        return count == 0;
    }
    
public:
    vector<string> removeInvalidParentheses(string s) {
        queue<string> bfsQ;
        bfsQ.push(s);
        unordered_set<string> seenWordsBefore;
        vector<string> result;
        
        while(!bfsQ.empty()){
            string curWord = bfsQ.front();
            bfsQ.pop();

            if (isValid(curWord)){
                result.push_back(curWord);
            }
            
            if (result.size() != 0){
                continue;
            }
            
            for(int i = 0; i < curWord.size(); i++){
                if (curWord[i] == '(' || curWord[i] == ')')
                {
                    string newWord = curWord;
                    newWord.erase(newWord.begin() + i);
                    if (seenWordsBefore.count(newWord) == 0)
                    {
                        seenWordsBefore.emplace(newWord);
                        bfsQ.push(newWord);
                    }
                }   
            }

        }
        
        return result;
    }
};
