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
public:
//it is important to do it in either clockwise or non clockwise direction only
vector<vector<int>> dir= {{-1,0},{0,1},{1,0},{0,-1}}; // this is the order of direction  because we go clockwise
set<pair<int,int>> visited;// we will imagine source to be 0,0 and start of grid
    void cleanRoom(Robot& robot) {
        //we need to always backtrack and move the robot be looking up
        backtrack(0,0,0,robot);
    }
    void goBack(Robot& robot){
        robot.turnRight();//turning back to go back
        robot.turnRight();
        robot.move();// actually going back
        robot.turnRight();//again setting up the robot to face forward
        robot.turnRight();
    }
    void backtrack(int x,int y,int direction,Robot& robot){
        visited.insert({x,y});
        robot.clean();
        //0 is going up, 1-> going right, 2->going down, 3->going left
        int newX,newY;
        for(int i=0;i<4;i++){
            int newDir= (direction+i)%4; // this would be the index of the direction array
            newX=x+dir[newDir][0];
            newY=y+dir[newDir][1];
            if(!visited.count({newX,newY}) && robot.move()){
                backtrack(newX,newY,newDir,robot);
                goBack(robot);
            }
            robot.turnRight();//move it to be 90, to go for next turn
        }
    }
};