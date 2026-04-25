#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    int n;
    vector<int> tree;

public:
    FenwickTree(int n) {
        this->n = n;
        tree.assign(n + 1, 0);
    }

    void update(int i, int delta) {
        while (i <= n) {
            tree[i] += delta;
            i += i & (-i);
        }
    }

    int query(int i) {
        int s = 0;
        while (i > 0) {
            s += tree[i];
            i -= i & (-i);
        }
        return s;
    }

    int range_query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    int n = 5;
    FenwickTree ft(n);

    vector<vector<int>> queries = {
        {1, 1, 5},
        {1, 2, 3},
        {2, 1, 2},
        {1, 5, 10},
        {2, 1, 5}
    };

    for (auto &q : queries) {
        if (q[0] == 1) {
            ft.update(q[1], q[2]);
        } else {
            cout << ft.range_query(q[1], q[2]) << endl;
        }
    }

    return 0;
}