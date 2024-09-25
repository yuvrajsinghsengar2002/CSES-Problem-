#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    long long n;
    vector<long long> segTree;
    vector<long long> lazy;

public:
    SegmentTree(long long n) {
        this->n = n;
        segTree.resize(4 * n + 2, 0);
        lazy.resize(4 * n + 2, 0);
    }

    void buildSegmentTree(long long arr[], long long index, long long low, long long high) {
        if (low == high) {
            segTree[index] = arr[low];
            return;
        }
        long long mid = low + (high - low) / 2;
        buildSegmentTree(arr, 2 * index + 1, low, mid);
        buildSegmentTree(arr, 2 * index + 2, mid + 1, high);
        segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
    }

    void RangeUpdate(long long index, long long low, long long high, long long l, long long r, long long val) {
        // Handle pending lazy updates
        if (lazy[index] != 0) {
            segTree[index] += (high - low + 1) * lazy[index];
            if (low != high) {
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }
            lazy[index] = 0;
        }

        // No overlap
        if (low > high || l > high || r < low) {
            return;
        }

        // Complete overlap
        if (low >= l && high <= r) {
            segTree[index] += (high - low + 1) * val;
            if (low != high) {
                lazy[2 * index + 1] += val;
                lazy[2 * index + 2] += val;
            }
            return;
        }

        // Partial overlap
        long long mid = low + (high - low) / 2;
        RangeUpdate(2 * index + 1, low, mid, l, r, val);
        RangeUpdate(2 * index + 2, mid + 1, high, l, r, val);
        segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
    }

    long long query(long long index, long long low, long long high, long long k) {
        // Handle pending lazy updates
        if (lazy[index] != 0) {
            segTree[index] += (high - low + 1) * lazy[index];
            if (low != high) {
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }
            lazy[index] = 0;
        }

        // No overlap
        if (low > high) {
            return 0;
        }

        // Single element
        if (low == high) {
            return segTree[index];
        }

        long long mid = low + (high - low) / 2;
        if (k <= mid) {
            return query(2 * index + 1, low, mid, k);
        } else {
            return query(2 * index + 2, mid + 1, high, k);
        }
    }
};

int main() {
    long long n, q;
    cin >> n >> q;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SegmentTree tree(n);
    tree.buildSegmentTree(arr, 0, 0, n - 1);
    while (q--) {
        long long type;
        cin >> type;
        if (type == 1) {
            long long a, b, c;
            cin >> a >> b >> c;
            tree.RangeUpdate(0, 0, n - 1, a - 1, b - 1, c);
        } else {
            long long k;
            cin >> k;
            cout << tree.query(0, 0, n - 1, k - 1) << endl;
        }
    }
    return 0;
}
