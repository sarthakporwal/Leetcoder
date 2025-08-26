class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& arr) {
        int n = arr.size();
        int maxD = 0, maxA = 0;

        for(int i = 0; i < n; i++){
            int l = arr[i][0];
            int b = arr[i][1];
            int area = l * b;
            int dia = (l*l + b*b);
            if(dia > maxD){
                maxD = dia;
                maxA = area;
            }else if(dia == maxD){
                maxA = max(maxA, area);
            }
        }

        return maxA;
    }
};