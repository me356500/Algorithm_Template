#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define vl vector<ll>
#define vvl vector<vector<ll>>
#define tu tuple<ll, ll, ll>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for(int i = 0; i < n; ++i)

// n nodes m edges

int n, m;
vl adj[100001], p(100001);
vvl cap(100001, vl(100001, 0));

int bfs(int s, int t) {
    fill(all(p), -1);
    p[s] = -2;
    queue<pll> q;
    q.emplace(make_pair(s, LLONG_MAX));
    
    for(; !q.empty(); q.pop()) {
        auto [from, flow] = q.front();
        for(auto to : adj[from]) {
            if(p[to] == -1 && cap[from][to]) {
                p[to] = from;
                ll tmp = min(flow, cap[from][to]);
                if(to == t)
                    return tmp;
                q.emplace(make_pair(to, tmp));
            }
        }
    }
    return 0;
}
// Edmonds-Karp
ll mflow(int s, int t) {
    ll flow = 0, nflow;

    while(nflow = bfs(s, t)) {
        flow += nflow;
        ll now = t;
        // augment path
        while(now != s) {
            ll pre = p[now];
            cap[pre][now] -= nflow;
            cap[now][pre] += nflow;
            now = pre;
        }
    }
    return flow;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m ;

    // 0 to n
    rep(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        // need bi-directional edges to build augmenting path
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        // one-directional edges
        cap[u][v] = w;
        
    }

    cout << mflow(0, n) << '\n';
}