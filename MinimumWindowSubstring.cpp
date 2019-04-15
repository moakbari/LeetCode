class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> charMap(256, 0);
        for_each(t.begin(), t.end(), [&charMap](const char& c){
            charMap[c]++;
        });
        
        int tLength = t.size();
        int startIndex = 0, endIndex = 0;
        int bestStartIndex = 0;
        int smallestLength = numeric_limits<int>::max();
        
        while(endIndex < s.size()){
            if(charMap[s[endIndex]] > 0){
               tLength--; 
            }
            
            charMap[s[endIndex]]--;
            endIndex++;
            
            while (tLength == 0){
                if (endIndex - startIndex  < smallestLength){
                    smallestLength = endIndex - startIndex;
                    bestStartIndex = startIndex;
                }
                
                if (charMap[s[startIndex]] == 0){
                   tLength++; 
                }
                
                charMap[s[startIndex]]++;
                startIndex++;
            }
        }
        
        return smallestLength == numeric_limits<int>::max() ? "" :
                s.substr(bestStartIndex, smallestLength);
    }
};
