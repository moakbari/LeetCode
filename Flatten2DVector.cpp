class Vector2D {
    vector<vector<int>> twoDVector_;
    int     rowSize_;
    int     curColSize_;
    int     curCol_;
    int     curRow_;

public:
    Vector2D(vector<vector<int>>& v)
    : twoDVector_(v)
    , rowSize_(v.size())
    , curColSize_(rowSize_ == 0 ? -1 : v[0].size())
    , curCol_(rowSize_ == 0 ? -1 : 0)
    , curRow_(rowSize_ == 0 ? -1 : 0)
    {
         while(curColSize_ == 0){
            curRow_++;
            if (curRow_ >= rowSize_){
                curRow_ = -1;
                curCol_ = -1;
                break;
            }else{
                curColSize_ = twoDVector_[curRow_].size();
                curCol_ = 0;
            }
        }
    }
    
    int next() {
        int retVal = twoDVector_[curRow_][curCol_];
        curCol_++;
        while(curCol_ >= curColSize_){
            curRow_++;
            if (curRow_ >= rowSize_){
                curRow_ = -1;
                curCol_ = -1;
                break;
            }else{
                curColSize_ = twoDVector_[curRow_].size();
                curCol_ = 0;
            }
        }
        
        return retVal;
    }
    
    bool hasNext() {
        if(curCol_ == -1 || curRow_ == -1){
            return false;
        }
        
        return true;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
