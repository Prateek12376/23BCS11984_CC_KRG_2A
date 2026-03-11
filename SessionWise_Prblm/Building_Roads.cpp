#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(NULL);

#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;
typedef map<int,int> mii;

#define mod 1000000007
#define endl '\n'
#define yes "Yes"
#define no "No"

#define pb push_back
#define F first
#define S second
#define range(a) a.begin(), a.end()
#define all(a) a.begin(), a.end()

#define loop(i,n) for(int i=0;i<n;i++)
#define revloop(i,n) for(int i=n-1;i>=0;i--)
#define inputarr(a,n) for(int i=0;i<n;i++) cin>>a[i]
#define it(a) for(auto it : a)

#define setbits(a) __builtin_popcountll(a)
#define msbit(a) 63-__builtin_clzll(a)
#define mspower(a) (1LL << (63-__builtin_clzll(a)))

#define lwb lower_bound
#define upb upper_bound

ll mod_add(ll a, ll b) { return (a + b) % mod; }
ll mod_mul(ll a, ll b) { return (a * b) % mod; }
ll mod_pow(ll a, ll b) {
    ll res = 1;
    while(b){
        if(b & 1) res = mod_mul(res, a);
        a = mod_mul(a, a);
        b >>= 1;
    }
    return res;
}
//1665c
void dfs(int u,vector<int>&vis,vii &adj){
    vis[u]=1;
    for(auto d:adj[u]){
        if(vis[d]==0){
            dfs(d,vis,adj);
        }
    }
}
void code(){
    int n,m;
    cin>>n>>m;
    vii adj(n+1);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi vis(n+1,0);
    vi ed;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
           ed.pb(i);
        dfs(i,vis,adj);
       
    }
    }
    cout<<ed.size()-1<<endl;
    for(int i=1;i<ed.size();i++){
        cout<<ed[i-1]<<" "<<ed[i];
        if(ed.size()-1!=i) cout<<endl;
    }
   
}

int32_t main(){
    fastio();
    int t = 1;
    //cin >> t;
    while(t--){
        code();
        cout << endl;
    }
    return 0;
}