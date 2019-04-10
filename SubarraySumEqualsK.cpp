class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumFrequency;
        int runningSum = 0;
        
        int totalNumber = 0;
        for (int i = 0; i < nums.size(); i++){
            runningSum += nums[i];
            
            if (runningSum == k){
                totalNumber++;
            }
                        
            if (sumFrequency.count(runningSum - k) != 0){
                totalNumber += (sumFrequency[runningSum - k]);
            }
            
            sumFrequency[runningSum]++;
        }
        
        return totalNumber;
    }
};
