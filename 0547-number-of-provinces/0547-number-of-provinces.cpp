class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& vis){
        vis[i] = true;
        for(auto it : adj[i]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& arr) {
        // Lets do it with both ways (BFS + DFS)
        int n = arr.size();

        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis(n, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};