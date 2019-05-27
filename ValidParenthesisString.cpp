class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<char, int>> parenStack;
        stack<pair<char, int>> starStack;
        
        int i = 0;
        while(i < s.size()) {
            if (s[i] == '('){
                parenStack.push(pair<char, int>(s[i], i));
            }else if(s[i] == '*'){
                starStack.push(pair<char, int>(s[i], i));
            }else{
                if(!parenStack.empty()){
                    parenStack.pop();
                }else{
                    if(starStack.empty()){
                        return false;
                    }
                    starStack.pop();
                }
            }
            
            i++;
        }
        
        while(!parenStack.empty()){
            if (starStack.empty()){
                return false;
            }
            
            if(parenStack.top().second < starStack.top().second){
                parenStack.pop();
                starStack.pop();
            }else{
                return false;
            }
        }
        
        return true;
        
    }
};
