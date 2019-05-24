class Solution {
public:
    // sum(p) - sum(n) = S; --> sum(p) - sum(n) + sum(p) + sum(n) = S + sum(nums) ---> 2*sum(p) = S + sum(nums) ---> sum(p) = (S+sum(nums)) /2 
    
    int findTargetSumWaysHelper(vector<int>& nums, int target){
        vector<int> Dp(target + 1, 0);
        Dp[0] = 1;
        
        for (int i = 0; i < nums.size(); i++){
            for (int j = target; j >= nums[i]; j--){
                Dp[j] += Dp[j - nums[i]];
            }
        }
        
        return Dp[target];
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        int sumNums = accumulate(nums.begin(), nums.end(), 0);
        return (S > sumNums || (S + sumNums) & 1) ? 0 : findTargetSumWaysHelper(nums, (S + sumNums) >> 1);
    }   
};
