class Solution {
    
    bool validPalindrome(const string& s, bool canErase){
        int start = 0, end = s.size() - 1;
        
        while(start < end){
            if (s[start] != s[end]){
                return canErase &&
                    (validPalindrome(s.substr(start, end - start), false) ||
                    validPalindrome(s.substr(start + 1, end - start), false));
            }
            
            start++;
            end--;
        }
        
        return true;
    }
    
public:
    bool validPalindrome(string s) {
        return validPalindrome(s, true);
    }
};
