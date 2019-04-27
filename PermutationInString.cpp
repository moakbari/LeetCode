class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()){
            return false;
        }
        
        vector<char> s1Map(26, 0);
        vector<char> s2Map(26, 0);
        
        for(int i = 0; i < s1.size(); i++){
            s1Map[s1[i] - 'a']++;
            s2Map[s2[i] - 'a']++;
        }
        
        if (s1Map == s2Map){
            return true;
        }
        
        for(int i = s1.size(); i < s2.size(); i++){
            s2Map[s2[i - s1.size()] - 'a']--;
            s2Map[s2[i] - 'a']++;
            
            if (s1Map == s2Map){
                return true;
            }
        }
        
        return false;
    }
};
