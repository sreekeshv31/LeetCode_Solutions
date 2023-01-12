class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        vector<int> result(n);
        dfs(labels, adj, 0, -1, &result);
        return result;
    }

private:
    vector<int> dfs(
        const string& labels,
        const vector<vector<int>>& adj,
        int node, int parent, vector<int> *result) {
        vector<int> count(26);
        for (const auto& child : adj[node]) {
            if (child == parent) {
                continue;
            }
            const auto& new_count = dfs(labels, adj, child, node, result);
            for (int k = 0; k < new_count.size(); ++k) {
                count[k] += new_count[k];
            }
        }
        (*result)[node] = ++count[labels[node] - 'a'];
        return count;
    }
};