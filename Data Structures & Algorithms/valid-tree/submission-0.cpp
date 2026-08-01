class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false; // a tree must have exactly n-1 edges

        
        unordered_map<int, vector<int>> adj;
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        unordered_set<int> visited;
        deque<pair<int,int>> queue; 
        queue.push_back({0, -1});
        visited.insert(0);

        while (!queue.empty()) {
            auto [node, parent] = queue.front();
            queue.pop_front();

            for (int neighbor : adj[node]) {
                if (neighbor == parent) continue;       
                if (visited.count(neighbor)) return false; 
                visited.insert(neighbor);
                queue.push_back({neighbor, node});
            }
        }

        return visited.size() == n;
    }
};