class Solution {
    
    struct lessOP{
        bool operator ()(const pair<int,int>& lhs, const pair<int,int>& rhs){
            return lhs.second < rhs.second;   
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for_each(nums.begin(), nums.end(), [&freqMap](const int& n){
            freqMap[n]++; 
        });
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, lessOP> maxHeap;
        
        for_each(freqMap.begin(), freqMap.end(), [&maxHeap](const pair<int,int>& e){
            maxHeap.push(e); 
        });
        
        vector<int> result;
        for(int i = 0; i < k && !maxHeap.empty(); i++){
            result.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        
        return result;
    }
};
