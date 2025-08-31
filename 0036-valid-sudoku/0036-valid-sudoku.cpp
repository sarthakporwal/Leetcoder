class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& arr) {
        unordered_set<string> st;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(arr[i][j] == '.') continue;

                string row = to_string(arr[i][j]) + "_row_" + to_string(i);
                string col = to_string(arr[i][j]) + "_col_" + to_string(j);
                string box = to_string(arr[i][j]) + "_box_" + to_string(i / 3) + to_string(j / 3);

                if(st.find(row) != st.end() || st.find(col) != st.end() || st.find(box) != st.end()){
                    return false;
                }
                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }

        return true;
    }
};