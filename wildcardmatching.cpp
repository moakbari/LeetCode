/*

if p[j] == '?' || s[i] == p[j]  then t[i][j] = t[i-1][j-1]

if p[j] == '*' then t[i][j] = t[i-1][j] || t[i][j-1] 

*/
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> t(s.size() + 1, vector<bool>(p.size() + 1, false));
        
        t[0][0] = true;
        
        for (int i = 0; i <= s.size(); i++){
            for (int j = 0; j <= p.size(); j++){
                
                if (i == 0 && j == 0){
                    continue;
                }
                
                if (j >= 1){
                    if (i >=1 && (p[j - 1] == '?' || s[i - 1] == p[j - 1])){
                        t[i][j] = t[i - 1][j - 1];
                    }else if (p[j - 1] == '*'){
                        t[i][j] = i >= 1 ? t[i][j - 1] || t[i-1][j] : t[i][j-1];
                    }
                }
            }
        }
        
        return t[s.size()][p.size()];
    }
};
