class Solution {
    string decode(const string& inp, int mul){
        string outp;
        for(int i = 0; i < mul; i++){
            outp += inp;
        }
        
        return outp;
    }
public:
    string decodeString(string s) {
        stack<int> multiplierStack;
        stack<string> lettersStack;
        
        int i = 0;
        while(i < s.size()) {
            if (isdigit(s[i])){
                int start = i;
                while(i < s.size() && isdigit(s[i])) {
                    i++;
                }
                
                string numstr = s.substr(start, i - start);
                multiplierStack.push(stoi(numstr));
            }else if (s[i] == ']') {
                string sub;
                while(!lettersStack.empty() && lettersStack.top() != "["){
                    sub = lettersStack.top() + sub;
                    lettersStack.pop();
                }
                lettersStack.pop();
                
                int mul = multiplierStack.top();
                multiplierStack.pop();
                string decoded = decode(sub, mul);
                lettersStack.push(decoded);
                i++;
            }else{
                string chartos(1, s[i]);
                lettersStack.push(chartos);
                i++;
            }
        }
    
        string finalDecoded;
        while(!lettersStack.empty()){
            finalDecoded = lettersStack.top() + finalDecoded;
            lettersStack.pop();
        }
        
        return finalDecoded;
    }
};
