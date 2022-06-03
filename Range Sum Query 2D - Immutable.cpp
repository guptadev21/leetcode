class NumMatrix {
    vector<vector<int>> M;
    
public:
    int** d;
    NumMatrix(vector<vector<int>>& matrix) {
        M = matrix;
        if (M.size() == 0 || M[0].size() == 0)
            return;
        d = new int*[M.size()];
        for (int i=0; i<M.size(); i++)
        {
            d[i] = new int[M[i].size()+1];
            for (int j=0; j<M[i].size(); j++)
            {
                d[i][j+1] = d[i][j] + M[i][j];
            }
        }
    }
    
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int s=0;
        for (int i=row1; i<=row2; i++)
        {
            s += d[i][col2+1] - d[i][col1];
        }
        return s;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
