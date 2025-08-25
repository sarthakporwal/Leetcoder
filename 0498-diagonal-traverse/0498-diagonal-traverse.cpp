class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        map<int, vector<int>> mp;
        // Storing the elements
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mp[i + j].push_back(mat[i][j]);
            }
        }

        // Checking for condition and getting the answer
        // we want element with odd idx,
        //but it will come in reverse fashion, so be careful
        bool flip = true;
        for(auto& it : mp){
            if(flip){
                reverse(it.second.begin(), it.second.end());
            }
            for(auto& num : it.second){
                ans.push_back(num);
            }
            flip = !flip;
        }
        
        return ans;
    }
};