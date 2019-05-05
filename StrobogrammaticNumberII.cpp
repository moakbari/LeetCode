class Solution {
    void findStrobogrammaticHelper(string curNum, int n, vector<string>& result, map<string,string>& stroMap){
        if (n == 0){
            if (curNum.size() != 0){
                result.push_back(curNum);
                return;
            }
        }
        
        for(map<string,string>::iterator iter = stroMap.begin(); 
            iter != stroMap.end(); iter++){
            if (iter->first == "0" && n == 2){
                continue;
            }
            
            string tempNum = curNum;
            tempNum = iter->first + tempNum + iter->second;
            findStrobogrammaticHelper(tempNum, n - 2, result, stroMap);
        }
    }
public:
    vector<string> findStrobogrammatic(int n) {
        map<string,string> stroMap = {{"0","0"}, {"1","1"}, {"6","9"}, {"8","8"}, {"9","6"}};
        vector<string> numToItself = {"0", "1", "8"};
        
        vector<string> result;
        if (n <= 0){
            return result;
        }
        
        string curNum;
        if(n % 2 == 0){  
            findStrobogrammaticHelper(curNum, n, result, stroMap);  
        }else{
            for(int i = 0; i < numToItself.size(); i++){
                curNum = numToItself[i];
                findStrobogrammaticHelper(curNum, n - 1, result, stroMap);
            }
        }
        
        return result;
    }
};
