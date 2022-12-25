#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define all(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define rep(i, n) for(int i = 0; i < n; ++i)

// vertex edges
set<ll> vc;
int n, m, timer = 0;
vl adj[100002], low, t, vis;
void dfs(int from, int p) {
    vis[from] = 1;
    low[from] = t[from] = timer;
    ++timer;
    ll sum = 0;
    for(const auto &to : adj[from]) {
        if(!to)
            continue;
        if(vis[to] == 1) {
            low[from] = min(low[from], t[to]);
        }
        else {
            dfs(to, from);
            low[from] = min(low[from], low[to]);
            if(low[to] >= t[from] && p) {
                vc.insert(from);
            }
            ++sum;
        }
    }
    if(!p && sum > 1)
        vc.insert(from);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    // n vertex start from 1
    low = t = vis = vl(n + 1, 0);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    // NULL parent = 0
    dfs(1, 0);
    cout << vc.size() << '\n';

    for(const auto &i : vc)
        cout << i << ' ';

}