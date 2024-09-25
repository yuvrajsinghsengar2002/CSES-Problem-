#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5+1;
const int logN = 20;

vector<vector<int>> p(maxN, vector<int>(logN));
vector<vector<int>> Graph(maxN);
vector<int> inTime(maxN), outTime(maxN), parents(maxN);
vector<int> value(maxN, 0);
vector<int> ans(maxN, 0);
int timer = 0;

bool ancestor(int u, int v) {
    return inTime[u] <= inTime[v] && outTime[u] >= outTime[v];
}

int lca(int u, int v) {
    if (ancestor(u, v)) return u;
    if (ancestor(v, u)) return v;
    for (int i = logN - 1; i >= 0; i--) {
        if (p[u][i] != -1 && !ancestor(p[u][i], v)) {
            u = p[u][i];
        }
    }
    return parents[u];
}

void dfs(int child = 1, int parent = -1) {
    parents[child] = parent;
    inTime[child] = timer++;
    p[child][0] = parent;

    for (int i = 1; i < logN; i++) {
        if (p[child][i - 1] != -1) {
            p[child][i] = p[p[child][i - 1]][i - 1];
        } else {
            p[child][i] = -1;
        }
    }

    for (auto it : Graph[child]) {
        if (it != parent) {
            dfs(it, child);
        }
    }

    outTime[child] = timer++;
}

int dfsForAnswer(int child, int parent) {
    int paths = value[child];
    for (auto it : Graph[child]) {
        if (it != parent) {
            paths += dfsForAnswer(it, child);
        }
    }
    return ans[child] = paths;
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    // Initialize p to -1
    for (int i = 0; i < maxN; i++) {
        fill(p[i].begin(), p[i].end(), -1);
    }

    // Perform DFS to prepare LCA computations
    dfs();

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int x = lca(a, b);
        value[a] += 1;
        value[b] += 1;
        value[x] -= 1;
        if (parents[x] != -1) {
            value[parents[x]] -= 1;
        }
    }

    // Perform DFS to compute the answers
    dfsForAnswer(1, -1);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
