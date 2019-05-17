class Solution {
    int expandAroundCenter(const string& s, int left, int right){
        int count = 0;
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            count++;
            left--;
            right++;
        }
        
        return count;
    }
public:
    int countSubstrings(string s) {
        int count  = 0;
        for(int i = 0; i < s.size(); i++){
            count += expandAroundCenter(s, i, i);
            count += expandAroundCenter(s, i, i+1);
        }
        
        return count;
    }
};
