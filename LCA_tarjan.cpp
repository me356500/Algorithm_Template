#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#pragma GCC optimize("O3", "unroll-loops")

using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long

#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define all(v) (v).begin(), (v).end()
#define tu tuple<ll, ll, ll>
#define pll pair<ll, ll>
#define rep(i, n) for(int i = 0; i < n; ++i)

int n, q;
vl adj[300005];
vector<pll> query[300005];
vl p, vis, dep;
// lca, u, v
vector<tu> ans;

ll find(int v) {
    return v == p[v] ? v : p[v] = find(p[v]);
}

void dfs(int v) {

    vis[v] = 1;
    for (const auto &u : adj[v]) 
        if (!vis[u]) {
            dep[u] = dep[v] + 1;
            dfs(u);
            p[u] = v;
        }
    
    for (const auto &[u, idx] : query[v]) 
        if(!(vis[u] ^ 2)) 
            get<0>(ans[idx]) = find(u); 
    
    vis[v] = 2;

}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> n;
    vis = dep = p = vl(n + 1, 0);
    iota(all(p), 0);

    ans = vector<tu>(n + 1, make_tuple(0, 0, 0));

    rep(i, n - 1) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    
    cin >> q;
    rep(i, q) {
        int u, v;
        cin >> u >> v;
        query[u].emplace_back(v, i);
        query[v].emplace_back(u, i);
        get<1>(ans[i]) = u;
        get<2>(ans[i]) = v;
    }
    dfs(1);
    
    rep(i, q) {
        auto &[lca, u, v] = ans[i];
        if(!lca) {
            cout << "0\n";
            continue;
        }
        cout << lca << '\n';
    }
        
}