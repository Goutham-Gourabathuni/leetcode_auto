class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> edges(n);
        vector<int> in_degree(n, 0);
        
        for (const auto& inv : invocations) {
            edges[inv[0]].push_back(inv[1]);
            in_degree[inv[1]]++;
        }
        
        queue<int> q;
        q.push(k);
        vector<bool> suspicious(n, false);
        suspicious[k] = true;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : edges[u]) {
                in_degree[v]--;
                if (!suspicious[v]) {
                    suspicious[v] = true;
                    q.push(v);
                }
            }
        }
        
        bool can_remove_all = true;
        for (int i = 0; i < n; i++) {
            if (suspicious[i] && in_degree[i] > 0) {
                can_remove_all = false;
                break;
            }
        }
        
        vector<int> ans;
        if (can_remove_all) {
            for (int i = 0; i < n; i++) {
                if (!suspicious[i]) ans.push_back(i);
            }
        } else {
            for (int i = 0; i < n; i++) ans.push_back(i);
        }
        return ans;
    }
};