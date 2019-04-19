class Solution {
    bool isValid(int i, int j, const vector<vector<int>>&  grid, vector<vector<bool>>& visited){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() 
            || grid[i][j] == 2 || grid[i][j] == 1 || visited[i][j]){
            return false;
        }
        
        return true;
    }
    
    void bfs(int i, int j, const vector<vector<int>>& grid, vector<vector<int>>& dist, vector<vector<bool>>& visited, vector<vector<int>>& pathToBuildings){
    
        queue<tuple<int, int, int>> bfsQ;
        bfsQ.push(tuple<int,int, int>(i,j, 0));
        visited[i][j] = true;
        while(!bfsQ.empty()){
            tuple<int,int, int> cur = bfsQ.front();
            int curI = get<0>(cur);
            int curJ = get<1>(cur);
            int curD = get<2>(cur);
            bfsQ.pop();
            
            if(isValid(curI + 1, curJ, grid, visited)){
                visited[curI + 1][curJ] = true;
                dist[curI + 1][curJ] = dist[curI + 1][curJ] == numeric_limits<int>::max() ?
                    curD + 1 : dist[curI + 1][curJ] + curD + 1;
                bfsQ.push(tuple<int,int, int>(curI + 1, curJ, curD + 1));
                pathToBuildings[curI+1][curJ]++;
            }
            
            if(isValid(curI, curJ + 1, grid, visited)){
                visited[curI][curJ + 1] = true;
                dist[curI][curJ + 1] = dist[curI][curJ + 1] == numeric_limits<int>::max() ?
                    curD + 1 : dist[curI][curJ + 1] + curD + 1;
                bfsQ.push(tuple<int,int, int>(curI, curJ + 1, curD + 1));
                pathToBuildings[curI][curJ+1]++;
            }
            
            if(isValid(curI - 1, curJ, grid, visited)){
                visited[curI - 1][curJ] = true;
                dist[curI - 1][curJ] = dist[curI - 1][curJ] == numeric_limits<int>::max() ?
                    curD + 1 : dist[curI - 1][curJ] + curD + 1;
                bfsQ.push(tuple<int,int, int>(curI - 1, curJ, curD + 1));
                pathToBuildings[curI-1][curJ]++;
            }            
            
            if(isValid(curI, curJ - 1, grid, visited)){
                visited[curI][curJ - 1] = true;
                dist[curI][curJ - 1] = dist[curI][curJ - 1] == numeric_limits<int>::max() ?
                    curD + 1 : dist[curI][curJ - 1] + curD + 1;
                bfsQ.push(tuple<int,int, int>(curI, curJ - 1, curD + 1));
                pathToBuildings[curI][curJ-1]++;
            }            
        }
    }
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if (grid.size() <= 0 || grid[0].size() <= 0){
            return -1;
        }
        
        vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), numeric_limits<int>::max()));
        vector<vector<int>> pathToBuildings(grid.size(), vector<int>(grid[0].size(), 0));
        int bestLocation = numeric_limits<int>::max();
        int totalNumberOfBuildings = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j =0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    totalNumberOfBuildings++;
                    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[i].size(),false));
                    int curMinDist = numeric_limits<int>::max();
                    bfs(i, j, grid, dist, visited, pathToBuildings);
                }
            }
        }
        
        for(int i = 0; i < dist.size(); i++){
            for(int j = 0; j < dist[i].size(); j++){
                if(pathToBuildings[i][j] == totalNumberOfBuildings){
                    bestLocation = min(bestLocation, dist[i][j]);
                }
            }
        }
        
        return bestLocation != numeric_limits<int>::max() ? bestLocation : -1;
        
    }
};
