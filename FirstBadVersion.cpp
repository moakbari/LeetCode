// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        int firstBad = -1;
        
        while(low <= high){
            int mid = (low - high) / 2 + high;
            if (isBadVersion(mid)){
                firstBad = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        return firstBad;
    }
};
