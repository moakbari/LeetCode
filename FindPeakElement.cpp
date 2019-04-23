class Solution {
    int findPeakElement(vector<int>& nums, int start, int end){
        if(start >= end){
            return end;
        }
        
        int mid = (start - end)/2 + end;
        
        if (mid != nums.size() - 1 && nums[mid] < nums[mid + 1]){
            return findPeakElement(nums, mid + 1, end);
        }else if (mid != 0 && nums[mid] < nums[mid - 1]){
            return findPeakElement(nums, start, mid - 1);
        }else{
            return mid;
        }
    }
public:
    int findPeakElement(vector<int>& nums) {
        return findPeakElement(nums, 0, nums.size()  - 1);
    }
};
