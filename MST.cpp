#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long

#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define all(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define tu tuple<int, int, int>

// Q plans N city M roads
int q, n, m;
vl a, vis, p, sz;
priority_queue<tu, vector<tu>, greater<tu> > edges;
int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;

    cin >> n >> m;
    // clear & initialize
    ll ans = 0, edge_num = 0;

    a = vl(n + 1, 0);
    sz = p = vl(n + 1, 1);
    iota(all(p), 0);

    // Input edges
    rep(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace(w, u, v);
    }


    for(;edges.size() && edge_num < n - 1; edges.pop()) {
        
        auto [w, u, v] = move(edges.top());
        u = find(u);
        v = find(v);
        if(u ^ v) {
            if(sz[u] < sz[v]) {
                p[u] = v;
                sz[v] += sz[u];
            }
            else {
                p[v] = u;
                sz[u] += sz[v];
            }
            ans += w;
            ++edge_num; 
        }
            
    }
        
    cout << ans << '\n';
    
}