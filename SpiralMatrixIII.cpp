class Solution {
    enum DIRECTION {RIGHT, DOWN, LEFT, UP};
    
    void updateNewPos(int& row, int& col, DIRECTION dir) {
        switch(dir){
            case RIGHT:
                col++;
                return;
            case DOWN:
                row++;
                return;
            case LEFT:
                col--;
                return;
            case UP:
                row--;
                return;
        }
    }
    
    bool isValid(int row, int col, int R, int C){
        return (row >=0 && row < R && col >= 0 && col < C);
    }
    
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int prevStepCount = 1;
        int stepCount = 1;
        int totalUnvisited = R*C;
        bool isSecondRound = false;
        int curRow = r0;
        int curCol = c0;
        vector<vector<int>> visitedCells;
        DIRECTION dir = RIGHT;
        
        do{
            //cout << curRow << ", " << curCol << endl;
            //cout << totalUnvisited << endl;
            if(isValid(curRow, curCol, R, C)) {
                vector<int> currentlyVisited;
                currentlyVisited.push_back(curRow);
                currentlyVisited.push_back(curCol);
                visitedCells.push_back(currentlyVisited);
                totalUnvisited--;
            }
            
            updateNewPos(curRow, curCol, dir);
            
            stepCount--;
            if (stepCount == 0) {
                stepCount = isSecondRound ? prevStepCount + 1 : prevStepCount;
                prevStepCount = stepCount;
                isSecondRound = !isSecondRound;
                dir = (DIRECTION) ((dir + 1) % 4);
            }
                                   
        }while(totalUnvisited > 0);
     
        return visitedCells;
    }
};
