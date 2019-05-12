class Solution {
    bool isPalindrom(const string& str){
        int start = 0;
        int end = str.size() - 1;
        while(start < end){
            if (str[start] != str[end]){
                return false;
            }
            
            start++;
            end--;
        }
        
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> reversedWords;
        for(int i = 0; i < words.size(); i++){
            string wordCopy = words[i];
            reverse(wordCopy.begin(), wordCopy.end());
            reversedWords.emplace(wordCopy, i);
        }
        
        vector<vector<int>> result;
        for (int i = 0; i < words.size(); i++)
        {
            // corner case where we have palindromic word and an empty string in dictionary
            if (isPalindrom(words[i]) && reversedWords.count("") && reversedWords[""] != i){
                vector<int> tempResult;
                tempResult.push_back(i);
                tempResult.push_back(reversedWords[""]);
                result.push_back(tempResult);
            }
            
            for(int index = 0; index < words[i].size(); index++)
            {
                string leftstr = words[i].substr(0, index + 1);
                string rightstr = words[i].substr(index + 1, string::npos);
                if (reversedWords.count(leftstr) && isPalindrom(rightstr) && reversedWords[leftstr] != i)
                {
                    vector<int> tempResult;
                    tempResult.push_back(i);
                    tempResult.push_back(reversedWords[leftstr]);
                    result.push_back(tempResult);
                }
                
                if (isPalindrom(leftstr) && reversedWords.count(rightstr) && reversedWords[rightstr] != i)
                {
                    vector<int> tempResult;
                    tempResult.push_back(reversedWords[rightstr]);
                    tempResult.push_back(i);
                    result.push_back(tempResult);
                }
            }
        }
        
        return result;
    }
};
