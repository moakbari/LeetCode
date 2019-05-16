class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medianVec;
        if (nums.size() == 0){
            return medianVec;
        }

        
        multiset<long, less<double>> minHeap;
        multiset<long, greater<double>> maxHeap;
        
        for(int i = 0; i < nums.size() ; i++){
            if (maxHeap.empty() || nums[i] <= *(maxHeap.begin())){
                maxHeap.emplace(nums[i]); 
            }else {
                minHeap.emplace(nums[i]);
            }
        
            if (maxHeap.size() > minHeap.size() + 1 ){
                minHeap.emplace(*(maxHeap.begin()));
                maxHeap.erase(maxHeap.begin());
            }else if (minHeap.size() > maxHeap.size() + 1){
                maxHeap.emplace(*(minHeap.begin()));
                minHeap.erase(minHeap.begin());
            }

            if (i >= k - 1){
                double median;
                if (k % 2 == 0){
                    double num1 = *(maxHeap.begin());
                    double num2 = *(minHeap.begin());
                    median = (num1 + num2) / 2.0;
                }else{
                    median = maxHeap.size() > minHeap.size() ? *(maxHeap.begin()) : *(minHeap.begin());
                }
                                                                  
                medianVec.push_back(median); 
                
                if (minHeap.count(nums[i - k + 1])){
                    minHeap.erase(minHeap.find(nums[i - k + 1]));
                }else{
                    maxHeap.erase(maxHeap.find(nums[i - k + 1]));
                }
                
                if (maxHeap.size() > minHeap.size() + 1 ){
                    minHeap.emplace(*(maxHeap.begin()));
                    maxHeap.erase(maxHeap.begin());
                }else if (minHeap.size() > maxHeap.size() + 1){
                    maxHeap.emplace(*(minHeap.begin()));
                    minHeap.erase(minHeap.begin());
                }
            }
        }
        
        return medianVec;
    }
};
