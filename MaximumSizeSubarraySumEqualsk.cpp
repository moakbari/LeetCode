class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int runningSum = 0;
        unordered_map<int, int> runningSumIndexMap;
        int largestSubarraySize = 0;
        
        for (int i = 0; i < nums.size(); i++){
            runningSum += nums[i];
            
            if (runningSum == k){
                largestSubarraySize = i + 1;
            }else{
                if (runningSumIndexMap.count(runningSum - k)){
                    largestSubarraySize = max(largestSubarraySize, i - runningSumIndexMap[runningSum - k]);
                }
            }
            
            if (runningSumIndexMap.count(runningSum) == 0){
                runningSumIndexMap.emplace(runningSum, i);
            }
            
        }
        
        return largestSubarraySize;
    }
};
