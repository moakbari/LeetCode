class Solution {
public:
    // if s[i] == p[j] || p[j] == '.' ---> T[i][j] = T[i-1][j-1]
    // if p[j] == '*' 
    //  -----> zero occurance: T[i][j] = T[i][j - 2]   OR
    //  -----> one or more occurance: if p[j - 1] == '.' || s[i] == p[j - 1] : T[i][j] = T[i-1][j]
    
    bool isMatch(string s, string p) {
        vector<vector<bool>> regexMatching(s.size() + 1, vector<bool>(p.size() + 1, false));
        regexMatching[0][0] = true;
        
        for (int j = 1; j <= p.size(); j++){
            if (p[j - 1] == '*'){
                regexMatching[0][j] = j == 1 ? true : regexMatching[0][j-2];
            }
        }
        
        for (int i = 1; i <= s.size(); i++){
            for (int j = 1; j <= p.size(); j++){
                if (p[j-1] == '.' || s[i-1] == p[j-1]){
                    regexMatching[i][j] = regexMatching[i-1][j-1];
                }else if (p[j-1] == '*'){
                    regexMatching[i][j] = regexMatching[i][j-2];
                    if (j >= 2 && (p[j-2] == '.' || s[i-1] == p[j-2])){
                        regexMatching[i][j] = regexMatching[i][j] | regexMatching[i-1][j];
                    }
                }
            }
        }
        
        return regexMatching[s.size()][p.size()];
        
    }
};
