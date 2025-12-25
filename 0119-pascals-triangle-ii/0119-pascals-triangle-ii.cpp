class Solution {
public:
    vector<int> getRow(int m) {
        vector<vector<int>> pas(m + 1);

        for(int i = 0; i < m + 1; i++){

            pas[i] = vector<int> (i + 1, 1);
            for(int j = 1; j < i; j++){
                pas[i][j] = pas[i - 1][j] + pas[i - 1][j - 1];
            }
        }
        return pas[m];
    }
};