#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n+1);

    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    vector<long long> dist(n+1, 1e18);
    vector<int> parent(n+1, -1);

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u]) continue;

        for(auto [v, w] : adj[u]){
            if(dist[v] > d + w){
                dist[v] = d + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if(dist[n] == 1e18){
        cout << -1 << "\n";
        return 0;
    }

    vector<int> path;
    for(int cur = n; cur != -1; cur = parent[cur]){
        path.push_back(cur);
    }

    reverse(path.begin(), path.end());

    for(int x : path) cout << x << " ";
    cout << "\n";

    return 0;
}