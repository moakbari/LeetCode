class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size()){
            return result;
        }
        vector<int> charMap(26, 0);
        for_each(p.begin(), p.end(), [&charMap](const char& c){
            charMap[c - 'a']++; 
        });
        
        int start = 0, end = 0;
        int pLength = p.size();
        
        for (;end < p.size(); end++)
        {
            if (charMap[s[end] - 'a'] > 0){
                pLength--;
            }
            charMap[s[end] - 'a']--;
        }
        
        if (pLength == 0){
            result.push_back(start);
        }
        
        while(end < s.size()){
            if(charMap[s[start] - 'a'] >= 0){
               pLength++; 
            }
            charMap[s[start] - 'a']++;
            start++;
            
            if (charMap[s[end] - 'a'] > 0){
                pLength--;
            }
            
            if(pLength == 0){
                result.push_back(start);
            }
            
            charMap[s[end] - 'a']--;
            end++;
        }
        
        return result;
    }
};
