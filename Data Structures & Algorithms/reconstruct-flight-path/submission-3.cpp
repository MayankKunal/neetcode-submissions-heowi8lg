class Solution {
    bool dfs(string node, unordered_map<string, multiset<string>>& mp, vector<string>& ans, int n) {
        if (ans.size() == n) return true; // complete itinerary found

        auto& edges = mp[node]; 
        // iterate with index since we'll erase/restore
        for (auto it = edges.begin(); it != edges.end(); ) {
            string next = *it;
            // erase this edge (consume ticket)
            it = edges.erase(it);

            ans.push_back(next);
            if (dfs(next, mp, ans, n)) return true; // stop if valid itinerary found
            ans.pop_back();

            // restore edge (backtracking)
            edges.insert(next);
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> mp;
        for (auto& ticket : tickets) {
            mp[ticket[0]].insert(ticket[1]);
        }

        vector<string> ans;
        ans.push_back("JFK");
        dfs("JFK", mp, ans, tickets.size() + 1);

        return ans;
    }
};
