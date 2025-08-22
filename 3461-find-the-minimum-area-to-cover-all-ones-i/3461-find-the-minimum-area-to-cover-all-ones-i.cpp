class Solution {
public:
    int minimumArea(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        int minR = m;
        int minC = n;
        int maxR = -1;
        int maxC = -1;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] == 1){
                    maxR = max(maxR, i);
                    maxC = max(maxC, j);
                    minR = min(minR, i);
                    minC = min(minC, j);
                }
            }
        }

        return (maxR - minR + 1)*(maxC - minC + 1);
    }
};