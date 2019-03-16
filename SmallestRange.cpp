class Solution {
public:
    
    struct HeapElement{
        int value;
        int vectorIndex;
        int elementIndex;
        HeapElement(int v, int ind, int eInd):value(v), vectorIndex(ind), elementIndex(eInd)
        {}

        bool operator > (const HeapElement& rhs) const{
            return value > rhs.value;
        }
    };
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int maxValue = numeric_limits<int>::min();
        priority_queue<HeapElement, vector<HeapElement>, greater<HeapElement>> minHeap;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++){
            if (nums[i].size() != 0){
                maxValue = max(maxValue,nums[i][0]);
                minHeap.push(HeapElement(nums[i][0], i, 0));
            }
        }
        
        while(!minHeap.empty()){
            HeapElement low = minHeap.top();
            
            minHeap.pop();
            
            if (result.empty() || maxValue - low.value < result[1] - result[0]){
                if (result.empty()){
                    result.push_back(low.value);
                    result.push_back(maxValue);
                }else{
                    result[0] = low.value;
                    result[1] = maxValue;
                }
            }
            
            if (low.elementIndex != nums[low.vectorIndex].size() - 1){
                minHeap.push(HeapElement(nums[low.vectorIndex][low.elementIndex + 1], low.vectorIndex, low.elementIndex + 1));
                maxValue = max(maxValue,nums[low.vectorIndex][low.elementIndex + 1]);
            }else{
                break;
            }
        }
        
        return result;
    }
};
