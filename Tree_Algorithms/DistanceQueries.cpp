#include <bits/stdc++.h> 
using namespace std;

int jump(int a, int k, vector<vector<int>>& up, int kmax) {
    for (int i = 0; i < kmax; i++) {
        if (k & (1 << i)) {
            a = up[i][a];
        }
    }
    return a;
}

void dfs(int i, int p, int d, vector<vector<int>>& adj, vector<int>& dist, vector<vector<int>>& up) {
    dist[i] = d;
    up[0][i] = p;
    for (auto t : adj[i]) {
        if (t != p) {
            dfs(t, i, d + 1, adj, dist, up);
        }
    }
}

int getDistance(int a, int b, vector<int>& dist, vector<vector<int>>& up, int kmax) {
    int d = abs(dist[a] - dist[b]);
    int ans = 0;
    a = jump(a, dist[a] - min(dist[a], dist[b]), up, kmax);
    b = jump(b, dist[b] - min(dist[a], dist[b]), up, kmax);
    if (a == b) {
        return d;
    }
    for (int i = kmax; i >= 0; i--) {
        if (up[i][a] != up[i][b]) {
            ans += 1 << i;
            a = up[i][a];
            b = up[i][b];
        }
    }
    if(a != b) {
        ans+=1;
    }
    ans *= 2;
    return ans + d;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    vector<int> dist(n + 1, 0);
    int kmax = ceil(log2(n + 1)) + 1;
    vector<vector<int>> up(kmax+1, vector<int>(n + 1, 0));
    for (int i = 2; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
        adj[a].push_back(b);
    } 
    dfs(1, 0, 0, adj, dist, up);
    for (int i = 1; i <= kmax; i++) {
        for (int j = 1; j <= n; j++) {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << getDistance(a, b, dist, up, kmax) << "\n";
    }
    return 0;
}
