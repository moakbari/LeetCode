class Solution {
    bool isValid(int i, int j, int curD, vector<vector<int>>& rooms){
        if( i < 0 || i >= rooms.size() || j < 0 || j >= rooms[i].size() || rooms[i][j] == 0 || rooms[i][j] == -1 || curD  > rooms[i][j]){
            return false;
        }
        
        return true;
    }

public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<tuple<int, int, int>> bfsQ;
        for(int i = 0; i < rooms.size(); i++){
            for (int j = 0; j < rooms[i].size(); j++){
                if (rooms[i][j] == 0){
                    bfsQ.push(tuple<int, int, int>(i, j, 0));
                }
            }
        }
        
        
        while(!bfsQ.empty()){
            tuple<int, int, int> cur = bfsQ.front();
            bfsQ.pop();
            int curI = get<0>(cur);
            int curJ = get<1>(cur);
            int curD = get<2>(cur);
            
            if(isValid(curI + 1, curJ, curD, rooms)){
                rooms[curI + 1][curJ] = min(rooms[curI + 1][curJ], curD + 1);
                bfsQ.push(tuple<int,int, int>(curI + 1, curJ, curD + 1));
            }
            
            if(isValid(curI, curJ + 1, curD, rooms)){
                rooms[curI][curJ + 1] = min(rooms[curI][curJ + 1], curD + 1);
                bfsQ.push(tuple<int,int, int>(curI, curJ + 1, curD + 1));
            }
            
            if(isValid(curI - 1, curJ, curD, rooms)){
                rooms[curI - 1][curJ] = min(rooms[curI - 1][curJ], curD + 1);
                bfsQ.push(tuple<int,int, int>(curI - 1, curJ, curD + 1));
            }            
            
            if(isValid(curI, curJ - 1, curD, rooms)){
                rooms[curI][curJ - 1] = min(rooms[curI][curJ - 1], curD + 1);
                bfsQ.push(tuple<int,int, int>(curI, curJ - 1, curD + 1));
            }  
        }
    }
};
