class Solution {
    struct Point{
        vector<int> xy;
        int distance;
        
        Point(const vector<int>& p)
        :xy(p)
        ,distance(p[0]*p[0] + p[1]*p[1])
        {}
        
        bool operator<(const Point& rhs) const{
            return distance < rhs.distance;
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<Point, vector<Point>, less<Point>> maxHeap;
        
        for(int i = 0; i < min((int)points.size(), K); i++)
        {
           maxHeap.push(Point(points[i])); 
        }

        for(int i = K; i < points.size(); i++){
            Point curP(points[i]);
            if (curP.distance < maxHeap.top().distance){
                maxHeap.pop();
                maxHeap.push(curP);
            }
        }
        
        vector<vector<int>> finalResult;
        while(!maxHeap.empty()){
            finalResult.push_back(maxHeap.top().xy);
            maxHeap.pop();
        }
        
        return finalResult;
    }
};
