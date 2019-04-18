class Solution {
    void parseLogEntry(const string& log, int& fun, string& soe, int& t){
        stringstream ss(log);
        string token;
            
        getline(ss, token, ':');
        fun = stoi(token);
        getline(ss, soe, ':');
        getline(ss, token, ':');
        t = stoi(token);

    }
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> timeSpent(n, 0);
        stack<int> funStack;
        if (logs.size() == 0 || logs.size() == 1){
            return timeSpent;
        }
        
        int funNum;
        string startOrEnd;
        int timeStamp, prevTimeStamp;
        
        for(int i = 0; i < logs.size() ; i++){
            parseLogEntry(logs[i], funNum, startOrEnd, timeStamp);
            
            if (startOrEnd == "start"){
                if(!funStack.empty()){
                    timeSpent[funStack.top()] += (timeStamp - prevTimeStamp); 
                }
                
                funStack.push(funNum);
                prevTimeStamp = timeStamp;
            }else{
                timeSpent[funNum] += (timeStamp - prevTimeStamp + 1);
                funStack.pop();
                prevTimeStamp = timeStamp + 1;
            }
        }
                
        return timeSpent;
    }
};
