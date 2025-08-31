class Solution {
public:
    bool valid(vector<vector<char>>& arr, char d, int i, int j){
        for(int k = 0; k < 9; k++){
            if(arr[i][k] == d) return false;
            if(arr[k][j] == d) return false;
        }
        int st = (i / 3) * 3;
        int end = (j / 3) * 3;

        for(int k = 0; k < 3; k++){
            for(int l = 0; l < 3; l++){
                if(arr[st + k][end + l] == d){
                    return false;
                }
            }
        }
        return true;
    }

    bool f(vector<vector<char>>& arr){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(arr[i][j] == '.'){
                    for(char d = '1'; d <= '9'; d++){
                        if(valid(arr, d, i, j) == true){
                           arr[i][j] = d;
                           if(f(arr) == true) return true;
                           arr[i][j] = '.';

                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& arr) {
        
        f(arr);
    }
};