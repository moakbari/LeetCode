class Solution {
    
    const static long moduloNum = pow(10, 9) + 7;
    using MapType = unordered_map<int, vector<int>>;
    
    void populateMoveMap(MapType& possibleMoves) {
        possibleMoves[0].push_back(4);
        possibleMoves[0].push_back(6);
        possibleMoves[1].push_back(6);
        possibleMoves[1].push_back(8);
        possibleMoves[2].push_back(9);
        possibleMoves[2].push_back(7);
        possibleMoves[3].push_back(8);
        possibleMoves[3].push_back(4);
        possibleMoves[4].push_back(9);
        possibleMoves[4].push_back(3);
        possibleMoves[4].push_back(0);
        possibleMoves.emplace(5, vector<int>());
        possibleMoves[6].push_back(1);
        possibleMoves[6].push_back(7);
        possibleMoves[6].push_back(0);
        possibleMoves[7].push_back(2);
        possibleMoves[7].push_back(6);
        possibleMoves[8].push_back(1);
        possibleMoves[8].push_back(3);
        possibleMoves[9].push_back(2);
        possibleMoves[9].push_back(4);
    }

public:
    int knightDialer(int N) {
        MapType possibleMoves;
        populateMoveMap(possibleMoves);
        
        vector<vector<int>> bottomUpTable(10, vector<int>(N + 1, 0));
        for(int i = 0; i <= 9; i++){
            bottomUpTable[i][1] = 1;
        }

        for(int j = 2; j <= N; j++) {
            for(int i = 0; i <= 9; i++){
                for(int k = 0; k < possibleMoves[i].size(); k++){
                    int newPos = possibleMoves[i][k];
                    bottomUpTable[i][j] += bottomUpTable[newPos][j - 1];
                    bottomUpTable[i][j] %= moduloNum;
                }
            }
        }
        
        int numOfDialed = 0;
        for(int i = 0; i <= 9; i++){
            numOfDialed += bottomUpTable[i][N];
            numOfDialed %= moduloNum;
        }
        
        return numOfDialed;
    }
};
