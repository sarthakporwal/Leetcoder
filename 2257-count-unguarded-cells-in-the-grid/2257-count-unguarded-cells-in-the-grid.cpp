class Solution {
public:
    void mark(vector<vector<int>>& arr, int row, int col){
        int m = arr.size(), n = arr[0].size();
        // UP
        for(int i = row - 1; i >= 0; i--){
            if(arr[i][col] == 2 || arr[i][col] == 3) break;
            arr[i][col] = 1;
        }
        // Right
        for(int i = col + 1; i < n; i++){
            if(arr[row][i] == 2 || arr[row][i] == 3) break;
            arr[row][i] = 1;
        }
        // Down
        for(int i = row + 1; i < m; i++){
            if(arr[i][col] == 2 || arr[i][col] == 3) break;
            arr[i][col] = 1;
        }
        // Left
        for(int i = col - 1; i >= 0; i--){
            if(arr[row][i] == 2 || arr[row][i] == 3) break;
            arr[row][i] = 1;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> arr(m, vector<int>(n, 0));
        for(vector<int>& it : guards){
            arr[it[0]][it[1]] = 2;
        }
        for(vector<int>& it : walls){
            arr[it[0]][it[1]] = 3;
        }

        for(vector<int>& it : guards){
            int r = it[0];
            int c = it[1];

            mark(arr, r, c);
        }

        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }
};