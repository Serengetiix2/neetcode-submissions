class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        unordered_set<int> visited;
        int regions = 0;

        for(int i = 0; i < edges.size(); ++i){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int s = 0; s < n; ++s){
            if(visited.find(s) != visited.end()) continue;
            
            deque<int> queue;
            queue.push_back(s);
            visited.insert(s);

            while(!queue.empty()){
                auto node = queue.front();
                queue.pop_front();

                for(auto n : adj[node]){
                    if(visited.find(n) == visited.end()){
                        queue.push_back(n);
                        visited.insert(n);
                    }
                    
                }
            }
            ++regions;

        }
        
        return regions;
    }
};