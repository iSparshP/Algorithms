class Solution {
public:
    void dfs(unordered_map<string, vector<pair<string, double>>>& adj, string src, string dst, unordered_set<string>& visited, double product, double& ans) {
        // If the source node is already visited, return
        if (visited.find(src) != visited.end()) {
            return;
        }
        
        // Mark the current node as visited
        visited.insert(src);
        
        // If the source is the same as the destination, update the answer
        if (src == dst) {
            ans = product;
            return;
        }
        
        // Explore all adjacent nodes
        for (auto& p : adj[src]) {
            string v = p.first;
            double val = p.second;
            dfs(adj, v, dst, visited, product * val, ans);
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        
        // Adjacency list to store the graph
        unordered_map<string, vector<pair<string, double>>> adj;
        
        // Build the graph
        for (int i = 0; i < n; i++) {
            string u = equations[i][0];   // Numerator
            string v = equations[i][1];   // Denominator
            double val = values[i];
            
            // Add both directions of the edge
            adj[u].push_back({v, val});        // u -> v
            adj[v].push_back({u, 1.0 / val}); // v -> u
        }
        
        vector<double> result;
        
        // Process each query
        for (auto& query : queries) {
            string src = query[0];
            string dst = query[1];
            double ans = -1.0;  // Default answer if no path exists
            double product = 1.0;
            unordered_set<string> visited;  // To keep track of visited nodes
            
            if (adj.find(src) != adj.end()) { // Check if the source exists in the graph
                dfs(adj, src, dst, visited, product, ans);
            }
            result.push_back(ans);
        }
        
        return result;
    }
};
