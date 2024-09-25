#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

struct StronglyConnectedComponents {
    int nodeCount;
    vector<vi> adj, reverseAdj;
    vi order, components, componentId;
    vector<bool> visited;
    
    void initialize(int _nodeCount) {
        nodeCount = _nodeCount;
        adj.resize(nodeCount);
        reverseAdj.resize(nodeCount);
        componentId = vi(nodeCount, -1);
        visited.resize(nodeCount);
    }
    
    void addEdge(int x, int y) {
        adj[x].push_back(y);
        reverseAdj[y].push_back(x);
    }
    
    void depthFirstSearch(int x) {
        visited[x] = true;
        for (auto y : adj[x]) {
            if (!visited[y]) {
                depthFirstSearch(y);
            }
        }
        order.push_back(x);
    }
    
    void reverseDepthFirstSearch(int x, int componentValue) {
        componentId[x] = componentValue;
        for (auto y : reverseAdj[x]) {
            if (componentId[y] == -1) {
                reverseDepthFirstSearch(y, componentValue);
            }
        }
    }
    
    void generateComponents(int _nodeCount) {
        for (int i = 1; i <= _nodeCount; i++) {
            if (!visited[i]) {
                depthFirstSearch(i);
            }
        }
        reverse(order.begin(), order.end());
        for (auto x : order) {
            if (componentId[x] == -1) {
                reverseDepthFirstSearch(x, x);
                components.push_back(x);
            }
        }
    }
};

const int MAXN = 1e5 + 5;

int nodeCount, edgeCount;
StronglyConnectedComponents scc;
int value[MAXN];
ll group[MAXN];
vi reverseGraph[MAXN];
ll dp[MAXN];

ll computeDP(int i) {
    if (dp[i]) return dp[i];
    dp[i] = group[i];
    for (auto j : reverseGraph[i]) {
        dp[i] = max(dp[i], computeDP(j) + group[i]);
    }
    return dp[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> nodeCount >> edgeCount;
    scc.initialize(nodeCount + 1);
    for (int i = 1; i <= nodeCount; i++) {
        cin >> value[i];
    }
    while (edgeCount--) {
        int a, b;
        cin >> a >> b;
        scc.addEdge(a, b);
    }

    scc.generateComponents(nodeCount);
    fill(dp + 1, dp + nodeCount + 1, 0);
    for (int i = 1; i <= nodeCount; i++) {
        group[scc.componentId[i]] += value[i];
    }
    for (int i = 1; i <= nodeCount; i++) {
        for (auto j : scc.adj[i]) {
            if (scc.componentId[i] == scc.componentId[j]) continue;
            reverseGraph[scc.componentId[j]].push_back(scc.componentId[i]);
        }
    }

    ll answer = 0;
    for (auto i : scc.components) {
        answer = max(answer, computeDP(i));
    }

    cout << answer << '\n';
}
