class Solution {
    bool detectCycle(int src, vector<int> adj[], vector<int>& vis, int parent) {
        vis[src] = 1;

        for (auto adjNode : adj[src]) {
            if (!vis[adjNode]) {
                if (detectCycle(adjNode, adj, vis, src))
                    return true;
            } else if (adjNode != parent) {
                return true; // Found a back edge, indicating a cycle
            }
        }
        return false;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // A tree must have exactly n-1 edges
        if (edges.size() != n - 1)
            return false;

        // Build the adjacency list
        vector<int> adj[n];
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n, 0);

        // Check for cycles starting from node 0
        if (detectCycle(0, adj, vis, -1))
            return false;

        // Ensure all nodes are connected
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                return false;
        }

        return true;
    }
};
