class Solution {
    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> tin, tout, depth, baseMask;
    int timer, LOG, n;

    // Fenwick Tree supporting range XOR updates and point queries
    vector<int> bit;

    void add(int idx, int val) {
        for (; idx <= n + 1; idx += idx & -idx)
            bit[idx] ^= val;
    }

    void rangeUpdate(int l, int r, int val) {
        add(l + 1, val);
        add(r + 2, val);
    }

    int pointQuery(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res ^= bit[idx];
        return res;
    }

    void dfs(int u, int p, string& s) {
        tin[u] = timer++;

        up[u][0] = p;

        for (int j = 1; j < LOG; j++)
            up[u][j] = up[up[u][j - 1]][j - 1];

        int charMask = 1 << (s[u] - 'a');

        if (u == p)
            baseMask[u] = charMask;
        else
            baseMask[u] = baseMask[p] ^ charMask;

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            dfs(v, u, s);
        }

        tout[u] = timer - 1;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++)
            if (diff & (1 << j))
                u = up[u][j];

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    int getPrefixMask(int u) {
        return baseMask[u] ^ pointQuery(tin[u] + 1);
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        this->n = n;
        timer = 0;

        LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;

        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        tin.resize(n);
        tout.resize(n);
        depth.assign(n, 0);
        baseMask.assign(n, 0);

        up.assign(n, vector<int>(LOG, 0));
        bit.assign(n + 2, 0);

        dfs(0, 0, s);

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            int u;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');
                int delta = oldMask ^ newMask;

                rangeUpdate(tin[u], tout[u], delta);
                s[u] = c;
            }
            else {
                int v;
                ss >> v;

                int w = lca(u, v);

                int mask = getPrefixMask(u)
                         ^ getPrefixMask(v)
                         ^ (1 << (s[w] - 'a'));

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};