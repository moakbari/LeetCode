class Solution {
    using CacheType = unordered_map<int, unordered_set<int>>;
    
    bool canPartitionHelper(vector<int>& nums, int index , int end, int curSum, int targetSum, CacheType& cache_){
        if (curSum == targetSum){
            return true;
        }
        
        if (index > end || curSum > targetSum || 
            (cache_.count(index) && cache_[index].count(curSum))){
            return false;
        }
        
        if (canPartitionHelper(nums, index + 1, end, curSum, targetSum, cache_) ||
            canPartitionHelper(nums, index + 1, end, curSum + nums[index], targetSum, cache_))
        {
            return true;
        }
        
        cache_[index].emplace(curSum);
        return false;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum == 0 || sum % 2 != 0){
            return false;
        }
        CacheType cache_;
        int targetSum = sum / 2;
        int curSum = 0;
        return canPartitionHelper(nums, 0, nums.size() - 1, curSum, targetSum, cache_);
    }
};
