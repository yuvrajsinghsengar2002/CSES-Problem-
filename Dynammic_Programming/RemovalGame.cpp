#include <bits/stdc++.h>
using namespace std;

long long solve(int turn, int i, int j, vector<vector<vector<long long>>> &dp, vector<long long> &arr) {
    if (i == j) {
        return turn == 0 ? arr[i] : 0;
    }
    if (i > j) return 0;
    if (dp[0][i][j] != LLONG_MIN) return dp[turn][i][j];

    if (turn == 0) {
            if(solve(1, i + 1, j, dp, arr) + arr[i] > solve(1, i, j - 1, dp, arr) + arr[j]){
                dp[turn][i][j] = solve(1, i + 1, j, dp, arr) + arr[i];
            }else{
                dp[turn][i][j] = solve(1, i, j - 1, dp, arr) + arr[j];
            }
    } else {
            if(solve(0, i + 1, j, dp, arr)+arr[i] > solve(0, i, j - 1, dp, arr)+arr[j]){
                dp[0][i][j] = solve(0, i + 1, j, dp, arr);

            }else{
                dp[0][i][j] = solve(0, i, j - 1, dp, arr);   
            }
    }
    return dp[0][i][j];
}

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Use LLONG_MIN to represent unvisited states
    vector<vector<vector<long long>>> dp(2, vector<vector<long long>>(n, vector<long long>(n, LLONG_MIN)));

    // Call the solve function starting with turn 0, from 0 to n-1
    long long result = solve(0, 0, n - 1, dp, arr);
    cout << result << endl;

    return 0;
}
