class NumMatrix {
    int rows_;
    int cols_;
    vector<vector<int>> matrix_;
    
    
    void preprocess(vector<vector<int>>& matrix){
        
        if (rows_ > 0 && cols_ > 0){
            matrix_[0][0] = matrix[0][0];
        }
        
        for(int i = 1; i < rows_; i++){
            matrix_[i][0] = matrix[i][0] + matrix_[i-1][0];
        }
        
        for(int j = 1; j < cols_; j++){
            matrix_[0][j] = matrix[0][j] + matrix_[0][j - 1];
        }
        
        for(int i = 1; i < rows_; i++){
            for(int j = 1; j < cols_; j++){
                matrix_[i][j] = matrix[i][j] + 
                   matrix_[i][j-1] + matrix_[i-1][j] -
                    matrix_[i-1][j-1];
            }
        }
    }
public:
    NumMatrix(vector<vector<int>>& matrix)
    : rows_(matrix.size())
    , cols_(matrix.size() ? matrix[0].size() : 0)
    , matrix_(rows_, vector<int>(cols_, 0))
    {
        preprocess(matrix);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int downLeft = 0;
        if (col1 - 1 >= 0){
            downLeft = matrix_[row2][col1 - 1];
        }
        
        int upRight = 0;
        if (row1 - 1 >= 0){
            upRight = matrix_[row1-1][col2];
        }
        
        int oppCorner = 0;
        if (row1 - 1 >= 0 && col1 - 1 >=0){
            oppCorner = matrix_[row1 - 1][col1 - 1];
        }
        
        return matrix_[row2][col2] - downLeft - upRight + oppCorner;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
