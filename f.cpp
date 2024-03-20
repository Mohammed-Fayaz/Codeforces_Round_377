#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    map<pair<int, int>, int> edgeMap;
    vector<vector<int>> graph(n, vector<int>());

    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edgeMap[{u, v}] = i;
        edgeMap[{v, u}] = i;
    }

    int cnt = 0;
    set<pair<int, int>> bridges;
    vector<int> visited(n, 0), tin(n, -1), low(n, -1);
    function<void(int, int)> dfs = [&](int u, int par){
        visited[u] = 1;
        tin[u] = low[u] = cnt++;
        for (auto v: graph[u]){
            if (v == par) continue;
            if (visited[v]) low[u] = min(low[u], low[v]);
            else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u]){
                    bridges.emplace(u, v);
                    bridges.emplace(v, u);
                }
            }
        }
    };

    dfs(0, -1);

    int node = -1;
    int res = 0;
    visited.assign(n, 0);
    function<int(int)> dfs2 = [&](int u){
        visited[u] = 1;

        int res = 1;
        for (auto v: graph[u]){
            if (bridges.find({u, v}) != bridges.end()) continue;
            if (!visited[v]) res += dfs2(v);
        }

        return res;
    };

    for (int u = 0; u < n; u++){
        if (!visited[u]){
            int sz = dfs2(u);
            if (sz > res){
                node = u;
                res = sz;
            }
        }
    }

    visited.assign(n, 0);
    vector<pair<int, int>> resEdges(m, {-1, -1});
    function<void(int)> dfs3 = [&](int u){
        visited[u] = 1;
        for (auto v: graph[u]){
            if (resEdges[edgeMap[{u, v}]] == pair<int, int>({-1, -1})){
                if (bridges.find({u, v}) != bridges.end()){
                    resEdges[edgeMap[{u, v}]] = {v, u};
                } else {
                    resEdges[edgeMap[{u, v}]] = {u, v};
                }
            }
            if (!visited[v]) dfs3(v);
        }
    };
    dfs3(node);

    cout << res << endl;
    for (auto edge: resEdges){
        cout << edge.first + 1 << " " << edge.second + 1 << endl;
    }
    return 0;
}
