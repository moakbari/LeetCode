class Solution {
    bool isOpr(const char& c){
        return c == '+' || c == '-' || c == '/' || c == '*';
    }
    
    string removeSpace(string s){
        int j = 0;
        for(int i = 0; i < s.size(); i++){
            if (s[i] != ' '){
                swap(s[i],s[j]);
                j++;
            }
        }
        
        return s.substr(0, j);
    }
    
    int getResult(int num1, int num2, char op){
        if(op == '-'){
            return num1 - num2;
        }else if(op == '+'){
            return num1 + num2;
        }else if (op == '*'){
            return num1*num2;
        }else{
            return num1/num2;
        }
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
                result = getResult(result, curNum, curOpr);
            }else{
                result = getResult(result - prev, curNum, curOpr) + prev;
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
