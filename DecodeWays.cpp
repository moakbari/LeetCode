/*
d[i] = 
if s[i] >= '1' && s[i] <= '9' then d[i+1]
+
if s[i,i+1] >= '10' && s[i,i+1] <= '26' then d[i+2]
*/
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()){
            return 0;
        }
        
        int m = (int) s.size();
        vector<int> d(m, 0);
        
        // string with length = 1;
        d[m - 1] = s[m - 1] != '0' ? 1 : 0;
        
        //string with legnth = 2
        if (m >= 2){
            d[m - 2] = stoi(s.substr(m - 2, 2)) >= 10 && stoi(s.substr(m - 2, 2)) <= 26 ?
                1 : 0;
            d[m - 2] = s[m - 2] >= '1' && s[m - 2] <= '9' ? d[m - 2] + d[m - 1] : d[m - 2];
        }
        
        for (int i = m - 3; i >= 0; i--){
            if (s[i] >= '1' && s[i] <= '9'){
                d[i] += d[i+1];
            }
            
            if (stoi(s.substr(i, 2)) >= 10 && stoi(s.substr(i, 2)) <= 26){
                d[i] += d[i+2];
            }
        }
        
        return d[0];
    }
};
