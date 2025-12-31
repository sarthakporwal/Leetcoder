class Solution {
public:
    int ROW, COL;
    int dRow[4] = {-1, 0, 1, 0};
    int dCol[4] = {0, 1, 0, -1};

    bool dfs(vector<vector<int>>& arr, int row, int col){
        if(row < 0 || col < 0 || row >= arr.size() || col >= arr[0].size() || arr[row][col] == 1){
            return false;
        }
        if(row == arr.size() - 1){
            return true;
        }
        arr[row][col] = 1;

        for(int i = 0; i < 4; i++){
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];
            // no need to undo
            if(dfs(arr, nRow, nCol) == true){
                return true;
            }
        }
        return false;
    }

    bool fill(vector<vector<int>>& cells, int mid){
        vector<vector<int>> arr(ROW, vector<int>(COL));

        for(int i = 0; i <= mid; i++){
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;

            arr[x][y] = 1;
        }

        for(int j = 0; j < COL; j++){
            if(arr[0][j] == 0 && dfs(arr, 0, j)){
                return true;
            }
        }
        return false;

    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        ROW = row;
        COL = col;
        int n = cells.size();
        int ans = 0;
        int st = 0, end = n - 1;
        while(st <= end){
            int mid = st + ((end - st) >> 1);

            if(fill(cells, mid) == true){
                ans = mid + 1;
                st = mid + 1;
            } else{
                end = mid - 1;
            }
        }
        return ans;
    }
};