class Solution {
    vector<int> runningSumVec;
    
    void doBinarySearch(int value, int& index, int start, int end){
        if (start > end){
            return;
        }
        int mid = (start + end) / 2;
        if (value <= runningSumVec[mid]){
            index = mid;
            return  doBinarySearch(value, index, start, mid - 1);
        }else{
            return doBinarySearch(value, index, mid + 1, end);
        }
    }
public:
    Solution(vector<int>& w) {
        int runningSum = 0;
        for(int i =0; i < w.size(); i++){
            runningSum += w[i];
            runningSumVec.push_back(runningSum);
        }
    }
    
    int pickIndex() {
        int value = rand() % runningSumVec.back() + 1;
        int index;
        if (value <= runningSumVec.front()){
            return 0;
        }else if (value == runningSumVec.back()){
            return runningSumVec.size() - 1;
        }else{
            doBinarySearch(value, index, 0, runningSumVec.size() - 1);
        }
        
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
