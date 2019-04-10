class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() == 0){
            return vector<int>();
        }
        
        vector<int> result(nums.size());
        result[nums.size() - 1] = nums.back();
        for(int i = nums.size() - 2; i >=0 ; i--){
            result[i] = nums[i]*result[i + 1];
        }
        
        int prodSofar = 1;;
        for (int i = 0; i < nums.size(); i++){
            if (i == nums.size() - 1){
                 result[i] =  prodSofar;  
            }else{
                result[i] = prodSofar*result[i+1];
                prodSofar *= nums[i];;
            }
        }
        
        return result;
    }
};
