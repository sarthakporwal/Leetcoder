class Solution {
public:
    bool check(vector<vector<int>>& grid, int row, int col){
        // checking 1 - 9 range 
        // and duplicate elements;
        unordered_set<int> s;
        for(int i = row; i < row + 3; i++){
            for(int j = col; j < col + 3; j++){
                if(grid[i][j] < 1 || grid[i][j] > 9 || s.count(grid[i][j])){
                    return false;
                }
                s.insert(grid[i][j]);
            }
        }
        // row and column check
        int rSum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];

        for(int i = 0; i < 3; i++){
            int rSumTemp = grid[row + i][col] + grid[row + i][col + 1] + grid[row + i][col + 2];
            int cSumTemp = grid[row][col + i] + grid[row + 1][col + i] + grid[row + 2][col + i];

            //checking
            if(rSumTemp != rSum) return false;
            if(cSumTemp != rSum) return false; 
        }

        // Diagonals check
        int dia = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int antiDia = grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2];
        if(dia != rSum) return false;
        if(antiDia != rSum) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        for(int i = 0; i <= m - 3; i++){
            for(int j = 0; j <= n - 3; j++){
                if(check(grid, i, j) == true){
                    ans++;
                }
            }
        }
        return ans;
    }
};