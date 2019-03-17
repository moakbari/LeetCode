class Solution {
    int searchHelper(vector<int>& nums, int low, int high, int target) {
        if (low > high){
            return -1;
        }
        
        int mid = low + (high - low) / 2;
        if (target == nums[mid]){
            return mid;
        }else{
            if (nums[low] <= nums[mid]){
                if (target >= nums[low] && target < nums[mid]){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }else{
                if (target > nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
            
            return searchHelper(nums, low, high, target);
        }
        
    }
public:
    int search(vector<int>& nums, int target) {
        return searchHelper(nums, 0, nums.size() - 1, target);
    }
};
