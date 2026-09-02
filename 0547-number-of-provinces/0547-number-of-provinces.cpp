class Solution {
public:
    void bfs(vector<vector<int>> &adj, int node, vector<bool>& vis){
        queue<int> qu;
        vis[node] = true;
        qu.push(node);

        while(!qu.empty()){
            int nn = qu.front();
            qu.pop();
            for(auto& nei : adj[nn]){ // adj[1] = [2,3,4], adj[7] = [8,9]
                if(vis[nei] == false){
                    vis[nei] = true;
                    qu.push(nei);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> vis(n + 1, false);
        int count = 0;
        for(int node = 0; node < n; node++){
            if(vis[node] == false){
                bfs(adj, node, vis);
                count++;
            }
        }
        return count;

    }
};