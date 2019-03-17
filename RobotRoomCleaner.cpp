/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
    enum DIRECTION {UP, LEFT, DOWN, RIGHT};
    
    pair<int,int> getNextRoomBasedOnDir(int x, int y, DIRECTION dir){
        switch(dir){
            case UP:
                return pair<int, int>(x-1, y);
            case LEFT:
                return pair<int, int>(x, y-1);
            case DOWN:
                return pair<int, int>(x+1, y);
            case RIGHT:
                return pair<int, int>(x, y+1);
            default:
                throw runtime_error("bad input!");
        }
    }
    
    DIRECTION nextDirection(DIRECTION dir){
        switch(dir){
            case UP:
                return LEFT;
            case LEFT:
                return DOWN;
            case DOWN:
                return RIGHT;
            case RIGHT:
                return UP;
            default:
                throw runtime_error("bad input!");
        }
    }
    
    void backtrackToOriginalRoom(Robot& robot){
        //Leave the robot in the original location with the original direction
        robot.turnLeft();
        robot.turnLeft();
        robot.move();
        robot.turnLeft();
        robot.turnLeft();
    }
    
    void cleanRoomHelper(Robot& robot, int x, int y, unordered_set<string>& cleanedRooms, DIRECTION curDir){
        robot.clean(); 
        cleanedRooms.emplace(to_string(x) + "->" + to_string(y));
    
        for (int count = 0; count < 4; count++){
            pair<int,int> nextRoom = getNextRoomBasedOnDir(x, y, curDir);
            if (cleanedRooms.count(to_string(nextRoom.first) + "->" + to_string(nextRoom.second)) == 0 && robot.move())                     {
                cleanRoomHelper(robot, nextRoom.first, nextRoom.second, cleanedRooms, curDir);
                backtrackToOriginalRoom(robot);
            }
            curDir = nextDirection(curDir);
            robot.turnLeft();
  
        }           
    }
public:
    void cleanRoom(Robot& robot) {
        unordered_set<string> cleanedRooms;
        cleanRoomHelper(robot, 0, 0, cleanedRooms, UP);
    }
};
