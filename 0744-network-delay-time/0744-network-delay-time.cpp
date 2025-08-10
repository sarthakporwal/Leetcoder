class Solution {
public:
    int networkDelayTime(vector<vector<int>>& arr, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for(auto &u : arr){
            adj[u[0]].push_back({u[1], u[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int ,int>>, greater<pair<int, int>>> pq;

        vector<int> d(n + 1, INT_MAX);
        pq.push({0, k});
        d[k] = 0;

        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;

            pq.pop();
            if(dist > d[node]) continue;

            for(auto &nei : adj[node]){
                int Ndist = nei.second;
                int Nnode = nei.first;

                if(dist + Ndist < d[Nnode]){
                    d[Nnode] = dist + Ndist;
                    pq.push({dist + Ndist, Nnode});
                }
            }
        }
        int ans = -1;
        for(int i = 1; i < d.size(); i++){
            if(d[i] == INT_MAX) return -1;
            else{
                ans = max(ans, d[i]);
            } 
        }
        return ans;
    }
};