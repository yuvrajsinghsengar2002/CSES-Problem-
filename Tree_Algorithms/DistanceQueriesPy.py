import sys

def jump(a, k, up, kmax):
    for i in range(kmax):
        if k & (1 << i):
            a = up[i][a]
    return a

def dfs(i, p, d, adj, dist, up):
    dist[i] = d
    up[0][i] = p
    for t in adj[i]:
        if t != p:
            dfs(t, i, d + 1, adj, dist, up)

def get_distance(a, b, dist, up, kmax):
    if dist[a] < dist[b]:
        a, b = b, a
    d = dist[a] - dist[b]
    ans = 0
    a = jump(a, d, up, kmax)
    if a == b:
        return d
    for i in range(kmax, -1, -1):
        if up[i][a] != up[i][b]:
            ans += 1 << i
            a = up[i][a]
            b = up[i][b]
    ans *= 2
    return ans + d

def main():
    n, q = map(int, input().split())
    adj = [[] for _ in range(n + 1)]
    dist = [0] * (n + 1)
    kmax = int((n + 1).bit_length()) + 1
    up = [[-1] * (n + 1) for _ in range(kmax)]
    for _ in range(2, n + 1):
        a, b = map(int, input().split())
        adj[b].append(a)
        adj[a].append(b)
    dfs(1, -1, 0, adj, dist, up)
    
    for _ in range(q):
        a, b = map(int, input().split())
        print(get_distance(a, b, dist, up, kmax))

if __name__ == "__main__":
    main()
