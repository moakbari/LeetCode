class Solution {
    int calculateRecursive(string s, int& index){
        
        int result = 0;
        bool isNegative = false;
        while(index < s.size() && s[index] != ')'){
            if(s[index] == '+' || s[index] == ' '){
                index++;
            }else if (s[index] == '-'){
                isNegative = true;
                index++;
            }else if (s[index] == '('){
                index++;
                result += isNegative ? -calculateRecursive(s, index) : calculateRecursive(s, index);
                isNegative = false;
            }else{
                int start = index;
                while(index < s.size() && isdigit(s[index])){
                    index++;
                }
                int num = stoi(s.substr(start, index - start)); 
                result += isNegative ? -num : num;
                isNegative = false;
            }
        }
        
        index++;
        return result;
    }
public:
    int calculate(string s) {
        int index = 0;
        return calculateRecursive(s, index);
    }
};
