class Solution {
public:
    int solve(vector<int>& arr, int n, int idx, vector<int>& dp){
        if(idx == (n - 1)) return 0;

        if(dp[idx] != -1) return dp[idx];
        int mini = 5656578;
        for(int i = 1; i <= arr[idx]; i++){
            if(idx + i < n){
                mini = min(mini, 1 + solve(arr, n, i + idx, dp));
            }
        }
        return dp[idx] = mini;
    }

    int jump(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(arr, n, 0, dp);
    }
};