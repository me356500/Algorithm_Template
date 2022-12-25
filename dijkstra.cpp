#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long

#define vl vector<ll>
#define pll pair<ll, ll>
#define rep(i, n) for(int i = 0; i < n; ++i)

//n city m roads
int n, m;
vector<pll> adj[200005];
vl dis;

void dij(int st) {
    dis = vl(n, LLONG_MAX);
    dis[st] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.emplace(0, st);
    for(; !pq.empty(); pq.pop()){ 
        auto [val, from] = pq.top();
        if(dis[from] < val)
            continue;

        for(const auto &[to, val]: adj[from]) 
            if(dis[to] > dis[from] + val) {
                dis[to] = dis[from] + val;
                pq.emplace(dis[to], to); 
            }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int start;
    // n node m edges 
    cin >> n >> m >> start;
    rep(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        //adj[v].emplace_back(u, w);
    }
    dij(start);
    rep(i, n)
        cout << (dis[i] == LLONG_MAX ? -1 : dis[i]) << ' ';

}
/*
7 10 0
0 1 2
0 2 7
2 1 3
1 3 2
0 4 12
4 6 -7
5 6 4
3 5 2
2 3 -5
2 4 2
*/