class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
           int row = grid.size(), col = grid[0].size();
        k = k % (row*col);
        vector<vector<int>> ans (row, vector<int>(col, 0));
        for(int idx = 0; idx < row*col ; idx++) {
            int new_idx = idx - k;
            if(new_idx < 0) new_idx += row*col;
            int new_row = (new_idx)/col; 
            int new_col = (new_idx)%col; 
            ans[idx/col][idx%col] = grid[new_row%row][new_col%col]; 
        }
        return ans;
        
    }
};