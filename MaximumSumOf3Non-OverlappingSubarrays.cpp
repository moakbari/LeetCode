class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        if (k == 0){
            return vector<int>();
        }
        
        
        vector<int> runSum(nums.size() + 1, 0);
        partial_sum(nums.begin(), nums.end(), runSum.begin() + 1);
       
        vector<int> leftIndex(nums.size(), -1);
        int leftMaxSum = numeric_limits<int>::min();
        for(int i = k - 1; i < nums.size() - 2*k; i++){
            int curSum = runSum[i + 1] - runSum[i - k + 1];
            leftIndex[i] = curSum > leftMaxSum ? i - k + 1 : leftIndex[i - 1];
            leftMaxSum = max(leftMaxSum, runSum[i + 1] - runSum[i + 1 - k]);
        }
        

        vector<int> rightIndex(nums.size(), -1);
        int rightMaxSum = numeric_limits<int>::min();
        for(int i = nums.size() - k; i >= 2*k; i--){
            int curSum = runSum[i + k] - runSum[i];
            rightIndex[i] = curSum > rightMaxSum ? i : rightIndex[i + 1];
            rightMaxSum = max (rightMaxSum, curSum);
        }  

        vector<int> result(3, -1);
        int totalMax = numeric_limits<int>::min();
        for(int i = k; i <= nums.size() - 2*k; i++){
            int l = leftIndex[i - 1];
            int r = rightIndex[i + k];
            int curSum = runSum[l + k] - runSum[l] +  runSum[i + k] - runSum[i] + runSum [r + k] - runSum[r];

            if (curSum > totalMax){
                totalMax = curSum;
                result[0] = l;
                result[1] = i;
                result[2] = r;
            }
        }
        
        return result;
    }
};
