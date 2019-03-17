class Solution {
    size_t findSubWithT(const string& S, size_t start, const string& T){
        int j = 0;
        while(start < S.size()){
            if (S[start] == T[j]){
                j++;   
                if (j >= T.size()){
                    break;
                }
            }
            start++;
        }
        
        return start;
    }
    
    int findSmallestWind(const string& S, const string& T, int end){
        int j = T.size() - 1;
        int i = end;
        while(i >= 0){
            if (S[i] == T[j]){
                j--;
                
                if (j < 0){
                    break;
                }
            }
            
            i--;
        }
        
        return i;
    }
    
public:
    string minWindow(string S, string T) {
        string window;
        if (S.empty() || T.empty()){
            return window;
        }
        
        size_t start = 0;
        size_t end = 0;
        while (true){
            start = S.find(T[0], start);
            if (start == string::npos){
                break;
            }
            
            end = findSubWithT(S, start, T);
            if (end == S.size()){
                break;
            }
            
            start = findSmallestWind(S, T, end);
            string candidate = S.substr(start, end - start + 1);
            if (window.empty() || candidate.size() < window.size()){
                window = candidate;
            }
            
            start++;
        }
        
        return window;   
    }
};
