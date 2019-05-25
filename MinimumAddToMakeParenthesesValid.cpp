class Solution {
public:
    int minAddToMakeValid(string S) {
        int diffCount = 0;
        int numberOfParanToAdd = 0;
        for(int i = 0; i < S.size(); i++){
            if (S[i] == '('){
                diffCount++;
            }else{
                diffCount--;
                if(diffCount < 0){
                    numberOfParanToAdd++;
                    diffCount = 0;
                }
            }
        }
        
        numberOfParanToAdd += abs(diffCount);
        
        return numberOfParanToAdd;
    }
};
