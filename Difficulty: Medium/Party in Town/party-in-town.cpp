class Solution {
public:
    pair<int,int> bfs(int src, vector<vector<int>>& adj) {
        int n = adj.size();

        vector<int> dist(n, -1);
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        int farthest = src;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (dist[u] > dist[farthest])
                farthest = u;

            for (int v : adj[u]) {
                int next = v - 1;

                if (dist[next] == -1) {
                    dist[next] = dist[u] + 1;
                    q.push(next);
                }
            }
        }

        return {farthest, dist[farthest]};
    }

    int partyHouse(vector<vector<int>>& adj) {
        auto first = bfs(0, adj);
        auto second = bfs(first.first, adj);

        int diameter = second.second;

        return (diameter + 1) / 2;
    }
};