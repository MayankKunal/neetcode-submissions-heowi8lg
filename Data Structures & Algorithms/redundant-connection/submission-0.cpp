class Solution {
    int findParent(int src, vector<int>& parent) {
        if (src == parent[src]) return src;
        return parent[src] = findParent(parent[src], parent); // Path compression
    }

    void connectedComponents(int u, int v, vector<int>& parent, vector<int>& findSize) {
        int rootU = findParent(u, parent);
        int rootV = findParent(v, parent);

        if (findSize[rootU] > findSize[rootV]) {
            parent[rootV] = rootU;
            findSize[rootU] += findSize[rootV];
        } else {
            parent[rootU] = rootV;
            findSize[rootV] += findSize[rootU];
        }
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);       // Initialize parent for 1-based indexing
        vector<int> findSize(n + 1, 1); // Size of each component initially 1

        for (int i = 1; i <= n; i++) {
            parent[i] = i; // Each node is its own parent initially
        }

        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            int rootU = findParent(u, parent);
            int rootV = findParent(v, parent);

            if (rootU == rootV) {
                // If both nodes have the same root, this edge forms a cycle
                return edge;
            } else {
                // Otherwise, union the two components
                connectedComponents(u, v, parent, findSize);
            }
        }

        return {};
    }
};
