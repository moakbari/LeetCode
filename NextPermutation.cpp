class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int candidateIndex = -1;
        for (int i = nums.size() - 1; i > 0; i--){
            if (nums[i] > nums[i - 1]){
                candidateIndex = i - 1;
                break;
            }
        }
        
        for (int i = nums.size() - 1; candidateIndex != -1 && i > candidateIndex; i--){
            if (nums[i] > nums[candidateIndex]){
                swap(nums[i], nums[candidateIndex]);
                break;
            }
        }
        
        reverse(nums.begin() + candidateIndex + 1, nums.end());
    }
};
