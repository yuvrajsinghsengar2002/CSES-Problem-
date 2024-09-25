#include<bits/stdc++.h>
using namespace std;

void topologicalSort(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &Stack) {
    visited[node] = true;
    for(auto i : adj[node]) {
        if(!visited[i])
            topologicalSort(i, adj, visited, Stack);
    }
    Stack.push(node);
}

void longestFlightRoute(int n, vector<int> &distance, vector<int> &parents, vector<vector<int>> &adj) {
    stack<int> Stack;
    vector<bool> visited(n+1, false);
    
    for(int i = 1; i <= n; i++) {
        if(!visited[i])
            topologicalSort(i, adj, visited, Stack);
    }
    
    distance[1] = 0;
    while(!Stack.empty()) {
        int node = Stack.top();
        Stack.pop();
        
        if(distance[node] != INT_MIN) {
            for(auto i : adj[node]) {
                if(distance[i] < distance[node] + 1) {
                    distance[i] = distance[node] + 1;
                    parents[i] = node;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<int> distance(n+1, INT_MIN);
    vector<int> parents(n+1, -1);
    longestFlightRoute(n, distance, parents, adj);
    
    if(distance[n] == INT_MIN) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> path;
    for(int node = n; node != -1; node = parents[node]) {
        path.push_back(node);
    }
    reverse(path.begin(), path.end());

    cout << path.size() << endl;
    for(auto node : path) {
        cout << node << " ";
    }

    return 0;
}
