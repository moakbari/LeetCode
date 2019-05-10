class Solution {
    bool isOpr(const char& c){
        return c == '+' || c == '-' || c == '/' || c == '*';
    }

public:
    int calculate(string s) {
        int prev = 0;
        int result = 0, start = 0, end = 0;
        while(end < s.size() && !isOpr(s[end])){
                end++;
        }
        
        result  = stoi(s.substr(start, end - start));
        char curOpr = end != s.size() ? s[end] : '/0';
        end++;
        start = end;
        
        while(end < s.size()){
            while(end < s.size() && !isOpr(s[end])){
                end++;
            }

            int curNum = stoi(s.substr(start, end - start));
            
            if (curOpr == '+' || curOpr == '-'){
                prev = result;
                result = curOpr == '+' ? result + curNum : result - curNum;
            }else{
                result = curNum == '*' ? (result - prev)*curNum + prev : (result - prev)/curNum + prev;
            }
            
            if (end == s.size()){
                break;
            }
            
            curOpr = s[end];
            end++;
            start = end;
        }
        
        return result;
    }
};
