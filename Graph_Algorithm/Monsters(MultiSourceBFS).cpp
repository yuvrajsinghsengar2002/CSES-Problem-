#include <bits/stdc++.h>
using namespace std;

vector<int> dirx = {-1, 0, 1, 0};
vector<int> diry = {0, 1, 0, -1};
vector<char> dir = {'U', 'R', 'D', 'L'};
vector<vector<int>> timing;
vector<vector<int>> parent;
int endX, endY;

bool bfsIndividual(vector<vector<char>> &grid, int n, int m, int startX, int startY, vector<vector<int>> &visited) {
    visited[startX][startY] = 1;
    queue<pair<int, int>> q;
    q.push({startX, startY});
    int timer = 1;
    while (!q.empty()) {
        int sz = q.size();
        while (sz > 0) {
            sz--;
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newx = x + dirx[i];
                int newy = y + diry[i];
                if (newx < 0 || newx >= n || newy < 0 || newy >= m || grid[newx][newy] == '#' || visited[newx][newy] == 1 || timing[newx][newy] <= timer) {
                    continue;
                } else if (newx == 0 || newx == n - 1 || newy == 0 || newy == m - 1) {
                    endX = newx;
                    endY = newy;
                    parent[newx][newy] = i;
                    return true;
                } else {
                    visited[newx][newy] = 1;
                    parent[newx][newy] = i;
                    q.push({newx, newy});
                }
            }
        }
        timer++;
    }
    return false;
}

void bfsMonster(vector<vector<char>> &grid, int n, int m, queue<pair<int, int>> &q, vector<vector<int>> &visited) {
    int timer = 1;
    while (!q.empty()) {
        int sz = q.size();
        while (sz > 0) {
            sz--;
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newx = x + dirx[i];
                int newy = y + diry[i];
                if (newx < 0 || newx >= n || newy < 0 || newy >= m || grid[newx][newy] == '#' || visited[newx][newy] == 1) {
                    continue;
                } else {
                    visited[newx][newy] = 1;
                    timing[newx][newy] = timer;
                    q.push({newx, newy});
                }
            }
        }
        timer++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> q;
    int startRow, startCol;
    vector<vector<char>> grid(n, vector<char>(m, 0));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    timing.resize(n, vector<int>(m, INT_MAX));
    parent.resize(n, vector<int>(m, -1));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                startRow = i;
                startCol = j;
            } else if (grid[i][j] == 'M') {
                visited[i][j] = 1;
                timing[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    if(startCol == 0 || startCol == m - 1 || startRow == 0 || startRow == n - 1){
        cout << "YES" << endl << 0 << endl; 
        return 0;
    }

    bfsMonster(grid, n, m, q, visited);
    visited.clear();
    visited.resize(n, vector<int>(m, 0));

    if (bfsIndividual(grid, n, m, startRow, startCol, visited)) {
        int x = endX;
        int y = endY;
        string ans = "";
        while (x != startRow || y != startCol) {
            ans += dir[parent[x][y]];
            int newx = x - dirx[parent[x][y]];
            int newy = y - diry[parent[x][y]];
            x = newx;
            y = newy;
        }
        reverse(ans.begin(), ans.end());
        cout << "YES" << endl << ans.length() << endl;
        cout << ans << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
