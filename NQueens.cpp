class Solution {
    bool canUseCurrentColumn(vector<int>& columns, int c, int r){
        for(int j = 0; j < columns.size(); j++){
            if(columns[j] != -1)
            {
                if ((j - columns[j]) == (r - c) ||
                    (j + columns[j]) == (r + c))
                {
                    return false;
                }
            }
        }
        
        return true;
    }
   void solveNQueensRecursive(int n, int rowNum, vector<int>& columns, vector<vector<string>>& finalResult)
   {
        if(rowNum == n){
            vector<string> curResult;
            for(int i = 0; i < n; i++){
                string rowStr;
                for(int j = 0; j < n; j++){
                    if (columns[i] == j){
                        rowStr.push_back('Q');
                    }else{
                        rowStr.push_back('.'); 
                    }
                }
                
                curResult.push_back(rowStr);
            }
            
            
            finalResult.push_back(curResult);
            return;
        }
       
        for(int i = 0; i < n; i++){
            if (find(columns.begin(), columns.end(), i) == columns.end())
            {
                if (canUseCurrentColumn(columns, i, rowNum)){
                    columns[rowNum] = i;
                    solveNQueensRecursive(n, rowNum + 1, columns, finalResult);
                    columns[rowNum] = -1;
                }
            }
       }
   }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> finalResult;
        vector<int> columns(n, -1);
        int rowNum = 0;
        solveNQueensRecursive(n, rowNum, columns,  finalResult);
        
        return finalResult;
    }
};
