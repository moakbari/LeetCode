class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prevSumSet;
        int runningSum = 0;
        
        
        for(int i = 0; i < nums.size(); i++){
            runningSum += nums[i];
            if (k != 0){
               runningSum = runningSum % k; 
            }
            
            if (i >=1 && runningSum == 0){
                return true;
            }
            
            if (prevSumSet.count(runningSum)){
                if (i - prevSumSet[runningSum] >= 2){
                    return true;
                }
            }else{
                prevSumSet[runningSum] = i;
            }
        }
        return false;
    }
};
