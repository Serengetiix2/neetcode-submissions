class Solution {
public:
    bool isConnected(vector<vector<int>>& adj, int start, int target) {
        unordered_set<int> visited;
        deque<int> queue;
        queue.push_back(start);
        visited.insert(start);

        while (!queue.empty()) {
            int cur = queue.front();
            queue.pop_front();
            if (cur == target) return true;

            for (int next : adj[cur]) {
                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    queue.push_back(next);
                }
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];

            // Check if u and v are already connected using edges added so far
            if (isConnected(adj, u, v)) {
                return edge; // this edge creates a cycle
            }

            // Otherwise, add this edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {}; // won't reach here given problem constraints
    }
};