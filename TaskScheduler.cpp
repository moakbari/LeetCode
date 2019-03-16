class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frequency(26, 0);
        
        for_each(tasks.begin(), tasks.end(), [&frequency](const char& c){
           frequency[(int) (c - 'A')]++; 
        });
        
        sort(frequency.begin(), frequency.end(), greater<int>());
        int numOfRemainingTasks = distance(frequency.begin(), find(frequency.begin(), frequency.end(), 0));  
        int intervals = 0;
        while(numOfRemainingTasks != 0){
            int waitPeriod = n;
            int index = 0;
            int idleTime = waitPeriod + 1 - numOfRemainingTasks;
            while(index < numOfRemainingTasks && waitPeriod >= 0){
                frequency[index]--;
                index++;
                waitPeriod--;
                intervals++;
            }
            
            sort(frequency.begin(), frequency.end(), greater<int>());
            numOfRemainingTasks = distance(frequency.begin(), find(frequency.begin(), frequency.end(), 0)); 
            
            intervals =  numOfRemainingTasks != 0 && idleTime > 0 ?  intervals + idleTime : intervals;  
        }
        
        return intervals;
    }
};
