class Solution {
public:
    int dRow[4] = {0, -1, 0, 1};
    int dCol[4] = {-1, 0, 1, 0};
    void dfs(vector<vector<int>> &arr, vector<vector<bool>> &vis, int row, int col, long long &ans){
        if(row < 0 || row >= arr.size() || col < 0 || col >= arr[0].size() || arr[row][col] == 0 || vis[row][col] == true) return;
    
        vis[row][col] = true;
        ans += arr[row][col];
    
        for(int i = 0; i < 4; i++){
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];
        
            dfs(arr, vis, nRow, nCol, ans);
        }
    }

    int countIslands(vector<vector<int>>& arr, int k) {
        int n = arr.size(), m = arr[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        int cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] != 0 && vis[i][j] == false){
                    long long ans = 0;
                    dfs(arr, vis, i, j, ans);
                    if(ans % k == 0){
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};







