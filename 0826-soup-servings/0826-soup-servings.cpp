class Solution {
public:
    double f(int a, int b, vector<vector<double>>& dp){
        if(a <= 0 && b > 0) return 1.0;
        else if(a <= 0 && b <= 0) return 0.5;
        else if(b <= 0 && a > 0) return 0.0;

        if(dp[a][b] != -1) return dp[a][b];

        double op1 = f(a - 100, b, dp);
        double op2 = f(a - 75, b - 25, dp);
        double op3 = f(a - 50, b - 50, dp);
        double op4 = f(a - 25, b - 75, dp);

        return dp[a][b] = (0.25 * (op1 + op2 + op3 + op4));

    }

    double soupServings(int n) {
        if (n > 5000) return 1.0;
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1.0));

        return f(n, n, dp);
    }
};