class Solution {
    int decodeWaysForOneChar(const string& s, int i){
        return s[i] == '*' ? 9 : s[i] == '0' ? 0 : 1;
    }
    
    int decodeWaysForTwoChars(const string& s, int i){
        return s[i] == '*' &&   s[i + 1] == '*' ? 15 :
               s[i] == '*' && s[i+1] >= '0' && s[i+1] <= '6' ? 2  :
               s[i] == '*' && s[i+1] >= '7' ? 1 :
               s[i+1] == '*' && s[i] == '1' ? 9 :
               s[i+1] == '*' && s[i] == '2' ? 6 :
               stoi(s.substr(i,2)) >= 10 && stoi(s.substr(i,2)) <= 26 ? 1 : 0;
    }
public:
    int numDecodings(string s) {
        if (s.size() == 0){
            return 0;
        }
        
        const long MOD = pow(10,9) + 7;
        
        int n = s.size() - 1;
        vector<long> decodeWays(n+1, 0);
        
        // 1- base case: s.size() == 1
        if (s.size() > 0){
            decodeWays[n] = decodeWaysForOneChar(s, n);
        }
        
        //2- base case: s.size() == 2
        if (s.size() > 1) {
            decodeWays[n - 1] = decodeWaysForOneChar(s, n - 1) * decodeWays[n] +
                                decodeWaysForTwoChars(s, n - 1);
        }
        
        //3- s.size() > 2
        for(int i = n - 2; i >= 0; i--){
           decodeWays[i] = (decodeWaysForOneChar(s, i)   * decodeWays[i + 1]) % MOD +
                           (decodeWaysForTwoChars(s, i) * decodeWays[i + 2]) % MOD;
        }
        
        return (int)(decodeWays[0] % MOD);
    }
};
