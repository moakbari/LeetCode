/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    struct timePoints{
        int value;
        bool isStart;
        
        timePoints(int v, bool st)
        :value(v)
        ,isStart(st)
        {}
        
        bool operator < (const timePoints& that){
            if (value == that.value){
                return isStart ? false : true;
            }
            
            return value < that.value;
        }
    };
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<timePoints> points;
        for_each(intervals.begin(), intervals.end(), [&points](const Interval& in){
            points.push_back(timePoints(in.start, true)); 
            points.push_back(timePoints(in.end, false)); 
        });
        
        sort(points.begin(), points.end());
        
        int maxRoomNumber = 0;
        int roomNumber = 0;
        for_each(points.begin(), points.end(), [&maxRoomNumber, &roomNumber](const timePoints& p)  {
            if (p.isStart){
                roomNumber++;
                maxRoomNumber = max(maxRoomNumber, roomNumber);
            }else{
                roomNumber--;
            }
        });
        
        return maxRoomNumber;
    }
};
