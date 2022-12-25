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
#define vc vector<char>
#define vvc vector<vector<char>>
#define all(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define tu tuple<int, int, int>

vl p, sz;

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

void merge(int u, int v) {
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
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    sz = p = vl(n + 1, 1);
    iota(all(p), 0);
}