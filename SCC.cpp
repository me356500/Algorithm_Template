#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repi(i, n) for(int i = 1; i <= n; ++i)
#define ll long long
#define ull unsigned long long
#define vl vector<ll>
int dfn[200005], low[200005];
int stk[200005], pa[200005];
int n, m, scc, idx;
stack<int>st;
vl adj[200005];

void tarjan(int now) {
    dfn[now] = low[now] = ++idx;
    stk[now] = 1;
    st.push(now);
    for (const auto &i : adj[now]) {
        if (!dfn[i]) {
            tarjan(i);
            low[now] = min(low[now], low[i]);
        }
        else if (stk[i]) 
            low[now] = min(low[now], dfn[i]);
    }
    if (dfn[now] == low[now]) {
        ++scc;
        int to = -1;
        while (to != now) {
            to = st.top();
            st.pop();
            stk[to] = 0;
            pa[to] = scc;
        }
    }
}
void solve() {
    // tarjan scc
    cin >> n >> m;
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
    }
    repi(i, n) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    // scc count
    cout << scc << '\n'; 
    // scc number
    repi(i, n) 
        cout << pa[i] << ' ';
    
    cout << '\n';
}