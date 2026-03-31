#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<vector<int>> adj(26);
    vector<int> indeg(26, 0);

    for (int i = 0; i < n - 1; i++) {
        string a = v[i], b = v[i + 1];
        int len = min(a.size(), b.size());
        bool found = false;

        for (int j = 0; j < len; j++) {
            if (a[j] != b[j]) {
                int u = a[j] - 'a';
                int v2 = b[j] - 'a';
                adj[u].push_back(v2);
                indeg[v2]++;
                found = true;
                break;
            }
        }

        if (!found && a.size() > b.size()) {
            cout << "Impossible\n";
            return 0;
        }
    }

    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    string ans = "";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans += char('a' + node);

        for (int it : adj[node]) {
            indeg[it]--;
            if (indeg[it] == 0) q.push(it);
        }
    }

    if (ans.size() != 26) {
        cout << "Impossible\n";
        return 0;
    }

    cout << ans << "\n";
}
